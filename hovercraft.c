#define BT Serial1
char state;
char acc;
int sp_f, sp_b, sp_l, sp_r=0;
int leftPWM = 11;
int leftDir = 10;
int rightPWM = 9;
int rightDir = 13; 
//int leftLevel,rightLevel;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(leftPWM,OUTPUT);
  pinMode(leftDir,OUTPUT);
  pinMode(rightPWM,OUTPUT);
  pinMode(rightDir,OUTPUT);
  pinMode(4,OUTPUT);
  while(!Serial);
  Serial.println("BT is ready!");
}
void Forward(int level,int level2){
  digitalWrite(leftDir,LOW);
  analogWrite(leftPWM,level);
  digitalWrite(rightDir,HIGH);
  analogWrite(rightPWM,level2);
}
void Backward(int level,int level2){
  digitalWrite(leftDir,HIGH);
  analogWrite(leftPWM,level);
  digitalWrite(rightDir,LOW);
  analogWrite(rightPWM,level2);
}
void Left(int level,int level2){
  digitalWrite(leftDir,HIGH);
  analogWrite(leftPWM,level);
  digitalWrite(rightDir,HIGH);
  analogWrite(rightPWM,level2);
}
void Right(int level,int level2){
  digitalWrite(leftDir,LOW);
  analogWrite(leftPWM,level);
  digitalWrite(rightDir,LOW);
  analogWrite(rightPWM,level2);
}
void Stop(){
  digitalWrite(leftDir,LOW);
  analogWrite(leftPWM,0);
  digitalWrite(rightDir,LOW);
  analogWrite(rightPWM,0);
}
void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    state=Serial.read();
    BT.write(state); 
    switch(state){ 
      case 'f':
        Forward(255,255);
        delay(100);
        Stop();
        break;
        
      case 'F':
        sp_f = sp_f + 30;
        Forward(100+sp_f,100+sp_f);
        break;
        
      case 'b':
        Backward(255,255);
        delay(100);
        Stop();
        break;
        
      case 'B':
        sp_b = sp_b + 30;
        Backward(100+sp_b,100+sp_b);
        break;
      
      case 'r':
        Right(255,255);
        delay(100);
        Stop();
        break;
        
      case 'R':
        sp_r = sp_r + 30;
        Right(100+sp_r,100+sp_r);
        break;
        
      case 'l':
        Left(255,255);
        delay(100);
        Stop();
        break;
        
      case 'L':
        sp_l = sp_l + 30;
        Left(100+sp_l,100+sp_l);
        break;
      
      case 's':
        Stop();
        sp_f=0;
        sp_r=0;
        sp_l=0;
        sp_b=0;
        break;

      case 'u':
        digitalWrite(4, HIGH);
        delay(100);
        digitalWrite(4, LOW);
        delay(100);
        break;
        
      default:
        break;
    }
  }

  
  while(BT.available()>0){
    state=BT.read();
    Serial.write(state);
    switch(state){ 
      case 'f':
        Forward(255,255);
        delay(100);
        Stop();
        break;
        
      case 'F':
        sp_f = sp_f +30;
        Forward(100+sp_f,100+sp_f);
        break;
      
      case 'b':
        Backward(255,255);
        delay(100);
        Stop();
        break;
        
      case 'B':
        sp_b = sp_b + 30;
        Backward(100+sp_b,100+sp_b);
        break;
      
      case 'r':
        Right(255,255);
        delay(100);
        Stop();
        break;
        
      case 'R':
        sp_r = sp_r + 30;
        Right(100+sp_r,100+sp_r);
      break;

      case 'l':
        Left(255,255);
        delay(100);
        Stop();
        break;
        
      case 'L':
        sp_l = sp_l + 30;
        Left(100+sp_l,100+sp_l);
        break;
      
      case 's':
        sp_f=0;
        sp_b=0;
        sp_l=0;
        sp_r=0;
        Stop();
        break;

      case 'u':
        digitalWrite(4, HIGH);
        delay(100);
                digitalWrite(4, LOW);
        delay(100);
        break;
        
      default:
        break;
    }
  }
}
