$NetBSD: patch-src_node.cc,v 1.1 2016/08/27 18:11:12 joerg Exp $

--- src/node.cc.orig	2016-08-26 20:21:02.722620766 +0000
+++ src/node.cc
@@ -3626,8 +3626,10 @@ static int RegisterDebugSignalHandler() 
   // Don't shrink the thread's stack on FreeBSD.  Said platform decided to
   // follow the pthreads specification to the letter rather than in spirit:
   // https://lists.freebsd.org/pipermail/freebsd-current/2014-March/048885.html
-#ifndef __FreeBSD__
+#if defined(__FreeBSD__)
   CHECK_EQ(0, pthread_attr_setstacksize(&attr, PTHREAD_STACK_MIN));
+#elif defined(__NetBSD__)
+  CHECK_EQ(0, pthread_attr_setstacksize(&attr, sysconf(_SC_THREAD_STACK_MIN)));
 #endif  // __FreeBSD__
   CHECK_EQ(0, pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED));
   sigset_t sigmask;
