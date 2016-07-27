$NetBSD: patch-progress.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- progress.c.orig	2016-07-27 20:12:55.358141535 +0000
+++ progress.c
@@ -7,18 +7,20 @@ char progress_RCSid[] = "Revision: 1.1 $
 
 #include "agm.h"
 
-void print_progress () {
+#include <signal.h>
+
+void print_progress (int unused) {
   printf ("%02d\b\b", pct);
   fflush (stdout);
 }
 
-void arm_timer ()
+void arm_timer (void)
 {
   struct sigaction action;
   struct itimerval tmr;
 
-  action.sa_handler = &print_progress;
-  action.sa_mask = 0;
+  action.sa_handler = print_progress;
+  sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   sigaction (SIGALRM, &action, NULL);
   
@@ -29,7 +31,7 @@ void arm_timer ()
   setitimer (ITIMER_REAL, &tmr, NULL);
 }
 
-void disarm_timer ()
+void disarm_timer (void)
 {
   struct sigaction action;
   struct itimerval tmr;
@@ -41,7 +43,7 @@ void disarm_timer ()
   setitimer (ITIMER_REAL, &tmr, NULL);
 
   action.sa_handler = SIG_DFL;
-  action.sa_mask = 0;
+  sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   sigaction (SIGALRM, &action, NULL);
 }
