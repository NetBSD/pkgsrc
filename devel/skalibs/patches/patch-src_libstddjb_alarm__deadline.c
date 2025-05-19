$NetBSD: patch-src_libstddjb_alarm__deadline.c,v 1.1 2025/05/19 14:35:38 schmonz Exp $

Apply upstream patches to fix "unable to set an alarm" on macOS.

--- src/libstddjb/alarm_deadline.c.orig	2021-08-10 18:42:57.000000000 +0000
+++ src/libstddjb/alarm_deadline.c
@@ -7,6 +7,7 @@
 #ifdef SKALIBS_HASTIMER
 
 #include <errno.h>
+#include <limits.h>
 #include <signal.h>
 #include <time.h>
 #include "alarm-internal.h"
@@ -22,7 +23,11 @@ int alarm_deadline (tain const *deadline
 {
   struct itimerspec it = { .it_interval = { .tv_sec = 0, .tv_nsec = 0 } } ;
   struct sigevent se = { .sigev_notify = SIGEV_SIGNAL, .sigev_signo = SIGALRM, .sigev_value = { .sival_int = 0 }, .sigev_notify_function = 0, .sigev_notify_attributes = 0 } ;
-  if (!timespec_from_tain(&it.it_value, deadline)) return 0 ;
+  if (!timespec_from_tain(&it.it_value, deadline))
+  {
+    it.it_value.tv_sec = INT_MAX ;
+    it.it_value.tv_nsec = 0 ;
+  }
   if (timer_create(MYCLOCK, &se, &timer_here) < 0) return 0 ;
   if (timer_settime(timer_here, TIMER_ABSTIME, &it, 0) < 0)
   {
