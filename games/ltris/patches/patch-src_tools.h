$NetBSD: patch-src_tools.h,v 1.1 2013/03/02 18:11:07 joerg Exp $

--- src/tools.h.orig	2013-03-01 22:02:58.000000000 +0000
+++ src/tools.h
@@ -33,7 +33,7 @@
 #define VEC_DIST( vec1, vec2 ) ( sqrt( ( vec1.x - vec2.x ) * ( vec1.x - vec2.x ) + ( vec1.y - vec2.y ) * ( vec1.y - vec2.y ) ) )
 
 /* compares to strings and returns true if their first strlen(str1) chars are equal */
-inline int strequal( char *str1, char *str2 );
+int strequal( char *str1, char *str2 );
 
 /* delete lines */
 void delete_lines( char **lines, int line_number );
@@ -45,16 +45,16 @@ typedef struct {
 } Delay;
 
 /* set delay to ms milliseconds */
-inline void delay_set( Delay *delay, int ms );
+void delay_set( Delay *delay, int ms );
 
 /* reset delay ( cur = 0 )*/
-inline void delay_reset( Delay *delay );
+void delay_reset( Delay *delay );
 
 /* check if time's out ( add ms milliseconds )and reset */
-inline int delay_timed_out( Delay *delay, int ms );
+int delay_timed_out( Delay *delay, int ms );
 
 /* set timer so that we have a time out next call of delay_timed_out() */
-inline void delay_force_time_out( Delay *delay );
+void delay_force_time_out( Delay *delay );
 
 /* return distance betwteen to map positions */
 int get_dist( int x1, int y1, int x2, int y2 );
