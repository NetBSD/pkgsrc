$NetBSD: patch-mysys_stacktrace.c,v 1.1 2016/09/16 06:49:11 adam Exp $

--- mysys/stacktrace.c.orig	2016-03-28 18:06:12.000000000 +0000
+++ mysys/stacktrace.c
@@ -245,7 +245,7 @@ void my_write_core(int sig)
 {
   signal(sig, SIG_DFL);
   pthread_kill(my_thread_self(), sig);
-#if defined(P_MYID)
+#if HAVE_SIGSEND && defined(P_MYID)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID,P_MYID,sig);
 #endif
