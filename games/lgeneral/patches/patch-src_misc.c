$NetBSD: patch-src_misc.c,v 1.1 2012/07/09 19:08:04 joerg Exp $

--- src/misc.c.orig	2012-07-06 16:15:05.000000000 +0000
+++ src/misc.c
@@ -31,20 +31,20 @@ inline int equal_str( char *str1, char *
 }
 
 /* set delay to ms milliseconds */
-inline void set_delay( Delay *delay, int ms )
+void set_delay( Delay *delay, int ms )
 {
     delay->limit = ms;
     delay->cur = 0;
 }
 
 /* reset delay ( cur = 0 )*/
-inline void reset_delay( Delay *delay )
+void reset_delay( Delay *delay )
 {
     delay->cur = 0;
 }
 
 /* check if times out and reset */
-inline int timed_out( Delay *delay, int ms )
+int timed_out( Delay *delay, int ms )
 {
     delay->cur += ms;
     if ( delay->cur >= delay->limit ) {
@@ -57,7 +57,7 @@ inline int timed_out( Delay *delay, int 
 }
 
 
-inline void goto_tile( int *x, int *y, int d )
+static inline void goto_tile( int *x, int *y, int d )
 {
     /*  0 -up, clockwise, 5 - left up */
     switch ( d ) {
