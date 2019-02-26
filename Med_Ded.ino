// The on-board LED
// pin assignments
int led = D7;

//threshold values 
//int val = 10;
int high = 30;
int low = 14;
int maxHeight = 100;

int opened =0;
int closed = 0;
int percent = 100;
int force =0;
int forceLimit =150;
int heightBefore;
int heightAfter;
int pressed;
int temp;
int height;
String EVENT_NAME;
float val;
float why;

void setup() {
//Time.zone(-5);
Time.setTime(1550373240);
  pinMode(led, OUTPUT);
 
}
void loop() {
  // Get some data
 // Particle.syncTime();
  val = val+1;
  String data = String(val);
  temp = random(1,100);
  height = random(1,100);
  percent = 100*height/maxHeight;
  

val = 3;
why = temp;
if (percent >50 || percent <20)
{
    opened = 1;
}

  
  if (temp > high){
      EVENT_NAME = String(3);
      Particle.publish("Events","3."+String(temp) + "°C",PRIVATE);
          delay(50000);
     
  }
  else if (temp <low){
      EVENT_NAME = String(2);
      Particle.publish("Events","2."+String(temp) + "°C",PRIVATE);
          delay(50000);
  }
  else if (opened)
  {
      //Event = String(0);
      Particle.publish("Events","0."+String(percent)+"% Full",PRIVATE);
      opened =0;
          delay(50000);
  }
  else if (closed){
     // Event = String(1);
      Particle.publish("Events","1."+String(percent)+"% Full",PRIVATE);
      closed =0;
          delay(50000);
  }
  // Wait 60 seconds
  delay(10000);
  
}