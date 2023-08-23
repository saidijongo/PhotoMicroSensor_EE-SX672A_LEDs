//int ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11}; // Array to store the LED pin numbers
int ledPins[] = {8, 9};
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]); // Number of LEDs connected

const int rightSensorPin = 11; // Pin number for the right photomicrosensor
const int leftSensorPin = 10;  // Pin number for the left photomicrosensor

boolean ledsOn = false; // Flag to control the state of LEDs

void setup() {
  // Initializing all LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Initializing photomicrosensor pins as INPUT with internal pull-up resistors
  pinMode(rightSensorPin, INPUT_PULLUP);
  pinMode(leftSensorPin, INPUT_PULLUP);
}

void loop() {
  // Checking if the right sensor is interrupted
  if (digitalRead(rightSensorPin) == LOW) {
    // Turning all LEDs on and off
    ledsOn = !ledsOn;
    if (ledsOn) {
      turnOnLEDs();
      delay(1000);
      turnOffLEDs();
      delay(1000);
    }
  }

  // Checking if the left sensor is interrupted
  if (digitalRead(leftSensorPin) == LOW) {
    // Blink LEDs one after another
    blinkLEDs();
  }
}

// Function to turn on all LEDs
void turnOnLEDs() {
  for (int pin = 0; pin < numLEDs; pin++) {
    digitalWrite(ledPins[pin], HIGH);
  }
}

// Function to turn off all LEDs
void turnOffLEDs(){
  for (int pin = 0; pin < numLEDs; pin++){
      digitalWrite(ledPins[pin], LOW);
  }
}

// Function to blink LEDs one after another
void blinkLEDs() {
  for (int pin = 0; pin < numLEDs; pin++){
    digitalWrite(ledPins[pin], HIGH);
    delay(1000);
    digitalWrite(ledPins[pin], LOW);
  }
}
