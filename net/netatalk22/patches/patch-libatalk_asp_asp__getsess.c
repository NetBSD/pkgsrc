$NetBSD: patch-libatalk_asp_asp__getsess.c,v 1.1 2021/09/12 15:52:37 nat Exp $

Allow -1 as a vaild tickleval to disable session tickles.
As needed on appletalk 58.

--- libatalk/asp/asp_getsess.c.orig	2014-09-01 17:19:35.000000000 +0000
+++ libatalk/asp/asp_getsess.c
@@ -163,8 +163,8 @@ ASP asp_getsession(ASP asp, server_child
 
       timer.it_interval.tv_sec = timer.it_value.tv_sec = tickleval;
       timer.it_interval.tv_usec = timer.it_value.tv_usec = 0;
-      if ((sigaction(SIGALRM, &action, NULL) < 0) ||
-	  (setitimer(ITIMER_REAL, &timer, NULL) < 0)) {
+      if (tickleval != -1 && ((sigaction(SIGALRM, &action, NULL) < 0) ||
+	  (setitimer(ITIMER_REAL, &timer, NULL) < 0))) {
 	free(asp_ac);
 	server_asp = NULL;
 	asp_ac = NULL;
