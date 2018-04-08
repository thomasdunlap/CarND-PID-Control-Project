#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  // Difference from previous error
  d_error = cte - p_error;

  // Set previous error to current cte
  p_error = cte;

  // Sum cte
  i_error += cte;
}

double PID::TotalError() {

  // Sum error across measures
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}
