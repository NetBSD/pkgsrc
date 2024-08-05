$NetBSD: patch-mysys_stacktrace.cc,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- mysys/stacktrace.cc.orig	2022-03-23 13:49:36.000000000 +0000
+++ mysys/stacktrace.cc
@@ -293,7 +293,7 @@ void my_print_stacktrace(const uchar *st
 void my_write_core(int sig) {
   signal(sig, SIG_DFL);
   pthread_kill(my_thread_self(), sig);
-#if defined(P_MYID)
+#if defined(HAVE_SIGSEND) && defined(P_MYID)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID, P_MYID, sig);
 #endif
