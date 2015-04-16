$NetBSD: patch-mysys_stacktrace.c,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- mysys/stacktrace.c.orig	2015-02-13 12:07:04.000000000 +0000
+++ mysys/stacktrace.c
@@ -455,7 +455,7 @@ void my_write_core(int sig)
   __gcov_flush();
 #endif
   pthread_kill(pthread_self(), sig);
-#if defined(P_MYID) && !defined(SCO)
+#if HAVE_SIGSEND && defined(P_MYID) && !defined(SCO)
   /* On Solaris, the above kill is not enough */
   sigsend(P_PID,P_MYID,sig);
 #endif
