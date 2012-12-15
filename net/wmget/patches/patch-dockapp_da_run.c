$NetBSD: patch-dockapp_da_run.c,v 1.1 2012/12/15 08:18:49 marino Exp $

Fix "variable 'rv' set but not used" error on gcc+4.6

--- dockapp/da_run.c.orig	2003-02-09 03:09:26.000000000 +0000
+++ dockapp/da_run.c
@@ -157,9 +157,8 @@ static void da_reset_timer (void)
 static long da_timer_msec_remaining (void)
 {
     struct timeval right_now;
-    int rv;
     
-    rv = gettimeofday (&right_now, 0);
+    gettimeofday (&right_now, 0);
 
     return
         (da_timer_next_timeout.tv_sec - right_now.tv_sec) * 1000L
