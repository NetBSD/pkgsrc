$NetBSD: patch-lib_signal-handler.c,v 1.1.2.2 2019/03/17 15:45:44 bsiegert Exp $
sigaction() is the old, compat syscall. On NetBSD call the up to date one.

--- lib/signal-handler.c.orig	2019-03-15 09:25:35.669181384 +0100
+++ lib/signal-handler.c	2019-03-15 09:29:02.023178726 +0100
@@ -45,6 +45,9 @@
 static int
 call_original_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
 {
+#ifdef __NetBSD__
+  __libc_sigaction14(signum, act, oldact);
+#else
   static int (*real_sa)(int, const struct sigaction *, struct sigaction *);
 
   if (real_sa == NULL)
@@ -52,6 +55,7 @@
       real_sa = dlsym(RTLD_NEXT, "sigaction");
     }
   return real_sa(signum, act, oldact);
+#endif
 }
 
 static gboolean
