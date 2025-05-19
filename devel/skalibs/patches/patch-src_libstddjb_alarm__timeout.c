$NetBSD: patch-src_libstddjb_alarm__timeout.c,v 1.1 2025/05/19 14:35:38 schmonz Exp $

Apply upstream patches to fix "unable to set an alarm" on macOS.

--- src/libstddjb/alarm_timeout.c.orig	2021-08-10 18:42:57.000000000 +0000
+++ src/libstddjb/alarm_timeout.c
@@ -7,6 +7,7 @@
 #ifdef SKALIBS_HASTIMER
 
 #include <errno.h>
+#include <limits.h>
 #include <signal.h>
 #include <time.h>
 #include "alarm-internal.h"
@@ -22,7 +23,11 @@ int alarm_timeout (tain const *tto)
 {
   struct itimerspec it = { .it_interval = { .tv_sec = 0, .tv_nsec = 0 } } ;
   struct sigevent se = { .sigev_notify = SIGEV_SIGNAL, .sigev_signo = SIGALRM, .sigev_value = { .sival_int = 0 }, .sigev_notify_function = 0, .sigev_notify_attributes = 0 } ;
-  if (!timespec_from_tain_relative(&it.it_value, tto)) return 0 ;
+  if (!timespec_from_tain_relative(&it.it_value, tto))
+  {
+    it.it_value.tv_sec = INT_MAX ;
+    it.it_value.tv_nsec = 0 ;
+  }
   if (timer_create(MYCLOCK, &se, &timer_here) < 0) return 0 ;
   if (timer_settime(timer_here, 0, &it, 0) < 0)
   {
@@ -38,12 +43,23 @@ int alarm_timeout (tain const *tto)
 #ifdef SKALIBS_HASITIMER
 
 #include <sys/time.h>
+#include <errno.h>
+#include <limits.h>
 
 int alarm_timeout (tain const *tto)
 {
   struct itimerval it = { .it_interval = { .tv_sec = 0, .tv_usec = 0 } } ;
-  if (!timeval_from_tain_relative(&it.it_value, tto)) return 0 ;
-  if (setitimer(ITIMER_REAL, &it, 0) < 0) return 0 ;
+  if (!timeval_from_tain_relative(&it.it_value, tto))
+  {
+    it.it_value.tv_sec = INT_MAX ;
+    it.it_value.tv_usec = 0 ;
+  }
+  if (setitimer(ITIMER_REAL, &it, 0) < 0)
+  {
+    if (errno != EINVAL) return 0 ;
+    it.it_value.tv_sec = 9999999 ;
+    if (setitimer(ITIMER_REAL, &it, 0) < 0) return 0 ;
+  }
   return 1 ;
 }
 
@@ -55,7 +71,7 @@ int alarm_timeout (tain const *tto)
 int alarm_timeout (tain const *tto)
 {
   int t = tain_to_millisecs(tto) ;
-  if (t < 0 || t > INT_MAX - 999) return 0 ;
+  if (t < 0 || t > INT_MAX - 999) t = INT_MAX - 999 ;
   t = (t + 999) / 1000 ;
   alarm(t) ;
   return 1 ;
