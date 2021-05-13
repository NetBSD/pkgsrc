$NetBSD: patch-mysys_stacktrace.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* make sure sigsend is available if used

--- mysys/stacktrace.cc.orig	2019-12-09 19:53:17.000000000 +0000
+++ mysys/stacktrace.cc
@@ -304,7 +304,7 @@ void my_print_stacktrace(const uchar *st
 void my_write_core(int sig) {
   signal(sig, SIG_DFL);
   pthread_kill(my_thread_self(), sig);
-#if defined(P_MYID)
+#if defined(HAVE_SIGSEND) && defined(P_MYID)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID, P_MYID, sig);
 #endif
