$NetBSD: patch-a60-mkc.inc,v 1.1 2014/01/02 04:02:59 dholland Exp $

Don't declare own time(), and call it correctly.

--- a60-mkc.inc~	1999-04-24 23:28:10.000000000 +0000
+++ a60-mkc.inc
@@ -224,9 +224,6 @@ b_rand ()
 {
 	static int first_time = 1;
 	static double rnum;
-#ifndef NO_TIME_FUNC
-	extern long time ();
-#endif
 
 	if (first_time) {
 		first_time = 0;
@@ -234,7 +231,7 @@ b_rand ()
 		/* sorry folks */
 		rnum = 1.0;
 #else
-		rnum = time ((long) 0) & 0xffffffl;
+		rnum = time ((time_t *) 0) & 0xffffffl;
 #endif
 	}
 
