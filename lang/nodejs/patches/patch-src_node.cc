$NetBSD: patch-src_node.cc,v 1.1 2016/05/27 23:30:51 fhajny Exp $

Handle NetBSD the same way as FreeBSD.

--- src/node.cc.orig	2016-05-17 19:53:07.000000000 +0000
+++ src/node.cc
@@ -3801,7 +3801,7 @@ static int RegisterDebugSignalHandler()
   // Don't shrink the thread's stack on FreeBSD.  Said platform decided to
   // follow the pthreads specification to the letter rather than in spirit:
   // https://lists.freebsd.org/pipermail/freebsd-current/2014-March/048885.html
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
   CHECK_EQ(0, pthread_attr_setstacksize(&attr, PTHREAD_STACK_MIN));
 #endif  // __FreeBSD__
   CHECK_EQ(0, pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED));
