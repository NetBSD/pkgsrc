$NetBSD: patch-src_process.c,v 1.1 2020/10/02 11:31:14 hauke Exp $

Linux glibc 2.32+ has removed sys_siglist

--- src/process.c.orig	2015-03-25 11:25:33.000000000 +0000
+++ src/process.c
@@ -1310,10 +1310,14 @@ See `set-process-sentinel' for more info
 const char *
 signal_name (int signum)
 {
+#if defined(LINUX) && !defined(SYS_SIGLIST_DECLARED)
+  return (const char *)strsignal(signum);
+#else
   if (signum >= 0 && signum < NSIG)
     return (const char *) sys_siglist[signum];
 
   return (const char *) GETTEXT ("unknown signal");
+#endif
 }
 
 void
