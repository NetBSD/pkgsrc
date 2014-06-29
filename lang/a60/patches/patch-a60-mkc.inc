$NetBSD: patch-a60-mkc.inc,v 1.2 2014/06/29 04:34:07 dholland Exp $

Don't declare own time(), and call it correctly.

--- a60-mkc.inc.orig	1999-04-24 23:28:10.000000000 +0000
+++ a60-mkc.inc
@@ -31,6 +31,7 @@
  */
 #include <stdio.h>
 #include <math.h>
+#include <time.h>
 
 #ifdef __STDC__
 #include <stdarg.h>
@@ -224,9 +225,6 @@ b_rand ()
 {
 	static int first_time = 1;
 	static double rnum;
-#ifndef NO_TIME_FUNC
-	extern long time ();
-#endif
 
 	if (first_time) {
 		first_time = 0;
@@ -234,7 +232,7 @@ b_rand ()
 		/* sorry folks */
 		rnum = 1.0;
 #else
-		rnum = time ((long) 0) & 0xffffffl;
+		rnum = time ((time_t *) 0) & 0xffffffl;
 #endif
 	}
 
