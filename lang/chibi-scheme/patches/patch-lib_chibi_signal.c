$NetBSD: patch-lib_chibi_signal.c,v 1.1 2020/05/09 19:07:00 leot Exp $

<sys/user.h> is no longer available on NetBSD, no need to include it.

--- lib/chibi/signal.c.orig	2015-05-10 13:47:12.000000000 +0000
+++ lib/chibi/signal.c
@@ -67,7 +67,9 @@ static sexp sexp_set_signal_action (sexp
 #include <sys/proc.h>
 #endif
 #include <sys/sysctl.h>
+#ifndef __NetBSD__
 #include <sys/user.h>
+#endif
 
 static sexp sexp_pid_cmdline (sexp ctx, int pid) {
   size_t reslen = sizeof(struct kinfo_proc);
