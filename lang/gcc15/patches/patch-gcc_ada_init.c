$NetBSD: patch-gcc_ada_init.c,v 1.1 2026/07/19 11:17:42 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/ada/init.c.orig	2026-06-12 06:09:05.877514473 +0000
+++ gcc/ada/init.c
@@ -2564,7 +2564,10 @@ __gnat_map_signal (int sig, siginfo_t *s
       /* Reset the use of alt stack, so that the alt stack will be used
 	 for the next signal delivery.
 	 The stack can't be used in case of stack checking.  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
       syscall (SYS_sigreturn, NULL, UC_RESET_ALT_STACK);
+#pragma GCC diagnostic pop
       break;

     case SIGFPE:
