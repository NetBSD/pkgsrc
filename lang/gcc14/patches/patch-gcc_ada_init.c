$NetBSD: patch-gcc_ada_init.c,v 1.2 2025/06/08 07:37:45 wiz Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/ada/init.c.orig	2025-05-23 11:02:04.044193610 +0000
+++ gcc/ada/init.c
@@ -2479,7 +2479,10 @@ __gnat_map_signal (int sig, siginfo_t *s
       /* Reset the use of alt stack, so that the alt stack will be used
 	 for the next signal delivery.
 	 The stack can't be used in case of stack checking.  */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
       syscall (SYS_sigreturn, NULL, UC_RESET_ALT_STACK);
+#pragma GCC diagnostic pop
       break;
 
     case SIGFPE:
