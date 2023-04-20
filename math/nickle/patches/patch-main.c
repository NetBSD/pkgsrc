$NetBSD: patch-main.c,v 1.1 2023/04/20 11:10:26 tnn Exp $

Fix wrong configure checks.

--- main.c.orig	2020-12-15 05:07:29.000000000 +0000
+++ main.c
@@ -179,7 +179,9 @@ stop (int sig)
 
 #if HAVE_RL_CLEANUP_AFTER_SIGNAL
     if (stdin_in_readline) {
+#if HAVE_RL_ECHO_SIGNAL_CHAR
 	rl_echo_signal_char(sig);
+#endif
 	rl_cleanup_after_signal();
     }
 #endif
@@ -197,7 +199,7 @@ stop (int sig)
     catchSignal (sig, stop);
     IoStart ();
 
-#if HAVE_RL_CLEANUP_AFTER_SIGNAL
+#if HAVE_RL_RESET_AFTER_SIGNAL
     if (stdin_in_readline)
 	rl_reset_after_signal();
 #endif
