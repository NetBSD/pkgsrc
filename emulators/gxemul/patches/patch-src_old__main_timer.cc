$NetBSD: patch-src_old__main_timer.cc,v 1.1 2019/03/03 10:41:28 gson Exp $

Set the SA_RESTART flag on SIGALRM so that it will not interrupt
writes to the console causing loss of console data.

--- src/old_main/timer.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/old_main/timer.cc
@@ -229,6 +229,7 @@ void timer_start(void)
 
 	memset(&saction, 0, sizeof(saction));
 	saction.sa_handler = timer_tick;
+	saction.sa_flags = SA_RESTART;
 
 	sigaction(SIGALRM, &saction, NULL);
 
