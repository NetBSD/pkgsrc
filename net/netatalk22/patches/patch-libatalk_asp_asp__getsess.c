$NetBSD: patch-libatalk_asp_asp__getsess.c,v 1.2 2022/01/28 21:18:19 nat Exp $

Allow -1 as a vaild tickleval to disable session tickles.
As needed on appletalk 58.

--- libatalk/asp/asp_getsess.c.orig	2014-09-01 17:19:35.000000000 +0000
+++ libatalk/asp/asp_getsess.c
@@ -163,8 +163,8 @@ ASP asp_getsession(ASP asp, server_child
 
       timer.it_interval.tv_sec = timer.it_value.tv_sec = tickleval;
       timer.it_interval.tv_usec = timer.it_value.tv_usec = 0;
-      if ((sigaction(SIGALRM, &action, NULL) < 0) ||
-	  (setitimer(ITIMER_REAL, &timer, NULL) < 0)) {
+      if (tickleval && ((sigaction(SIGALRM, &action, NULL) < 0) ||
+	  (setitimer(ITIMER_REAL, &timer, NULL) < 0))) {
 	free(asp_ac);
 	server_asp = NULL;
 	asp_ac = NULL;
