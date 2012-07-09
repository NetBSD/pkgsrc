$NetBSD: patch-src_misc.h,v 1.1 2012/07/09 19:08:04 joerg Exp $

--- src/misc.h.orig	2012-07-06 16:15:20.000000000 +0000
+++ src/misc.h
@@ -51,13 +51,13 @@ typedef struct {
 } Delay;
 
 /* set delay to ms milliseconds */
-inline void set_delay( Delay *delay, int ms );
+void set_delay( Delay *delay, int ms );
 
 /* reset delay ( cur = 0 )*/
-inline void reset_delay( Delay *delay );
+void reset_delay( Delay *delay );
 
 /* check if time's out ( add ms milliseconds )and reset */
-inline int timed_out( Delay *delay, int ms );
+int timed_out( Delay *delay, int ms );
 
 /* return distance betwteen to map positions */
 int get_dist( int x1, int y1, int x2, int y2 );
