$NetBSD: patch-src_signals.c,v 1.1 2012/02/16 14:05:08 hans Exp $

--- src/signals.c.orig	2000-03-15 23:13:29.000000000 +0100
+++ src/signals.c	2012-01-20 13:11:43.374363790 +0100
@@ -45,11 +45,14 @@ trapsignals (void)
 void
 suspend (int n)
 {
+	sigset_t set;
+
 	restoreterm();
 	signal(SIGTSTP, SIG_DFL);
-	sigsetmask(sigblock(0) &~ mask(SIGTSTP));
+	sigaddset(&set, SIGTSTP);
+	sigprocmask(SIG_UNBLOCK, &set, NULL);
 	kill(0, SIGTSTP);
-	sigblock(mask(SIGTSTP));
+	sigprocmask(SIG_BLOCK, &set, NULL);
 	signal(SIGTSTP, suspend);
 	icbterm();
 	continued = 1;
