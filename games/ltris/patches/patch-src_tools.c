$NetBSD: patch-src_tools.c,v 1.1 2013/03/02 18:11:07 joerg Exp $

--- src/tools.c.orig	2013-03-01 22:02:55.000000000 +0000
+++ src/tools.c
@@ -23,27 +23,27 @@
 #include "ltris.h"
 
 /* compares to strings and returns true if their first strlen(str1) chars are equal */
-inline int strequal( char *str1, char *str2 )
+int strequal( char *str1, char *str2 )
 {
     if ( strlen( str1 ) != strlen( str2 ) ) return 0;
     return ( !strncmp( str1, str2, strlen( str1 ) ) );
 }
 
 /* set delay to ms milliseconds */
-inline void delay_set( Delay *delay, int ms )
+void delay_set( Delay *delay, int ms )
 {
     delay->limit = ms;
     delay->cur = 0;
 }
 
 /* reset delay ( cur = 0 )*/
-inline void delay_reset( Delay *delay )
+void delay_reset( Delay *delay )
 {
     delay->cur = 0;
 }
 
 /* check if times out and reset */
-inline int delay_timed_out( Delay *delay, int ms )
+int delay_timed_out( Delay *delay, int ms )
 {
     delay->cur += ms;
     if ( delay->cur >= delay->limit ) {
@@ -56,12 +56,12 @@ inline int delay_timed_out( Delay *delay
 }
 
 /* set timer so that we have a time out next call of delay_timed_out() */
-inline void delay_force_time_out( Delay *delay )
+void delay_force_time_out( Delay *delay )
 {
     delay->cur = delay->limit;
 }
 
-inline void goto_tile( int *x, int *y, int d )
+void goto_tile( int *x, int *y, int d )
 {
     /*  0 -up, clockwise, 5 - left up */
     switch ( d ) {
@@ -326,24 +326,24 @@ Counter with a current float value and a
 the target value until reached when counter_update() is called.
 ====================================================================
 */
-inline void counter_set( Counter *counter, double value )
+void counter_set( Counter *counter, double value )
 {
     counter->value = value;
     counter->approach = value;
 }
-inline void counter_add( Counter *counter, double add )
+void counter_add( Counter *counter, double add )
 {
     counter->value += add;
 }
-inline double counter_get_approach( Counter counter )
+double counter_get_approach( Counter counter )
 {
     return counter.approach;
 }
-inline double counter_get( Counter counter )
+double counter_get( Counter counter )
 {
     return counter.value;
 }
-inline void counter_update( Counter *counter, int ms )
+void counter_update( Counter *counter, int ms )
 {
     double change;
     if ( counter->approach == counter->value ) return;
