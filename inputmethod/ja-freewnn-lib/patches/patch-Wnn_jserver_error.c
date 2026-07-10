$NetBSD: patch-Wnn_jserver_error.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Use proper signal handler type
- Use proper variadic arguments to print error messages

--- Wnn/jserver/error.c.orig	2003-06-08 03:09:51.000000000 +0000
+++ Wnn/jserver/error.c
@@ -244,8 +244,10 @@ signal_hand (x)
 }
 
 RETSIGTYPE
-terminate_hand ()
+terminate_hand (x)
+     int x;
 {
+  (void) x;
   daemon_fin ();
   exit (0);
 
@@ -268,13 +270,15 @@ exit_hand ()
 
 /* Replace with log_debug()? */
 void
-out (x, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12)
-     char *x;
-     int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12;
+out (char *x, ...)
 {
+  va_list ap;
+
   if (!noisy)
     return;
-  fprintf (stderr, x, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12);
+  va_start (ap, x);
+  vfprintf (stderr, x, ap);
+  va_end (ap);
   fflush (stderr);
 }
 
