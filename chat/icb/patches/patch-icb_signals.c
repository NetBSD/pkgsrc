$NetBSD: patch-icb_signals.c,v 1.1 2012/02/16 14:13:15 hans Exp $

--- icb/signals.c.orig	1995-02-24 22:20:29.000000000 +0100
+++ icb/signals.c	2012-01-20 15:51:46.655776885 +0100
@@ -40,11 +40,14 @@ trapsignals()
 sighandler
 suspend()
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
