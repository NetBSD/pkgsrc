$NetBSD: patch-mysys_stacktrace.c,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- mysys/stacktrace.c.orig	2021-09-14 09:08:08.000000000 +0000
+++ mysys/stacktrace.c
@@ -259,7 +259,7 @@ void my_write_core(int sig)
 {
   signal(sig, SIG_DFL);
   pthread_kill(my_thread_self(), sig);
-#if defined(P_MYID)
+#if HAVE_SIGSEND && defined(P_MYID)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID,P_MYID,sig);
 #endif
