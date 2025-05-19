$NetBSD: patch-src_libstddjb_alarm__milliseconds.c,v 1.1 2025/05/19 14:35:38 schmonz Exp $

Apply upstream patches to fix "unable to set an alarm" on macOS.

--- src/libstddjb/alarm_milliseconds.c.orig	2021-07-28 15:04:32.000000000 +0000
+++ src/libstddjb/alarm_milliseconds.c
@@ -36,11 +36,17 @@ int alarm_milliseconds (unsigned int t)
 #ifdef SKALIBS_HASITIMER
 
 #include <sys/time.h>
+#include <errno.h>
 
 int alarm_milliseconds (unsigned int t)
 {
   struct itimerval it = { .it_interval = { .tv_sec = 0, .tv_usec = 0 }, .it_value = { .tv_sec = t / 1000, .tv_usec = 1000 * (t % 1000) } } ;
-  if (setitimer(ITIMER_REAL, &it, 0) < 0) return 0 ;
+  if (setitimer(ITIMER_REAL, &it, 0) < 0)
+  {
+    if (errno != EINVAL) return 0 ;
+    it.it_value.tv_sec = 9999999 ;
+    if (setitimer(ITIMER_REAL, &it, 0) < 0) return 0 ;
+  }
   return 1 ;
 }
 
