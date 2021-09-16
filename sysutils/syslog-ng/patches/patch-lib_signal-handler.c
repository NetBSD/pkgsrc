$NetBSD: patch-lib_signal-handler.c,v 1.3 2021/09/16 09:32:03 wiz Exp $

sigaction() is the old, compat syscall. On NetBSD call the up to date one.
https://github.com/syslog-ng/syslog-ng/pull/3786

--- lib/signal-handler.c.orig	2021-06-09 18:47:52.838429049 +0200
+++ lib/signal-handler.c	2021-06-09 18:48:47.322106570 +0200
@@ -84,12 +84,16 @@
 static int
 _original_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
 {
+#ifdef __NetBSD__
+  __libc_sigaction14(signum, act, oldact);
+#else
   static int (*real_sa)(int, const struct sigaction *, struct sigaction *);
 
   if (real_sa == NULL)
     real_sa = dlsym(RTLD_NEXT, "sigaction");
 
   return real_sa(signum, act, oldact);
+#endif
 }
 
 static gint
