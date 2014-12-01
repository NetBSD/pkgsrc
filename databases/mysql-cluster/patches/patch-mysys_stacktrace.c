$NetBSD: patch-mysys_stacktrace.c,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

--- mysys/stacktrace.c.orig	2013-01-22 16:54:49.000000000 +0000
+++ mysys/stacktrace.c
@@ -420,7 +420,7 @@ void my_write_core(int sig)
 {
   signal(sig, SIG_DFL);
   pthread_kill(pthread_self(), sig);
-#if defined(P_MYID) && !defined(SCO)
+#if HAVE_SIGSEND && defined(P_MYID) && !defined(SCO)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID,P_MYID,sig);
 #endif
