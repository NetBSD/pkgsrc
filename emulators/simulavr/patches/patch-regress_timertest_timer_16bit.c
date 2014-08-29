$NetBSD: patch-regress_timertest_timer_16bit.c,v 1.2 2014/08/29 04:40:06 mef Exp $

error: attempt to use poisoned "VARNAME"

--- work/simulavr-1.0.0/regress/timertest/timer_16bit.c	2012-02-13 00:26:38.000000000 +0900
+++ regress/timertest/timer_16bit.c	2013-08-08 09:25:31.000000000 +0900
@@ -4,14 +4,14 @@
 volatile int timer_ticks;
 
 #ifdef T3TEST
-ISR(SIG_OVERFLOW3) {
+ISR(TIMER3_OVF_vect) {
    timer_ticks++;
 }
-ISR(SIG_OUTPUT_COMPARE3B) {
+ISR(TIMER3_COMPB_vect) {
    timer_ticks++;
 }
 #else
-ISR(SIG_OVERFLOW1) {
+ISR(TIMER1_OVF_vect) {
    timer_ticks++;
 }
 #endif
