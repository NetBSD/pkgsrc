$NetBSD: patch-src_inspector__agent.cc,v 1.1 2017/06/05 21:14:04 fhajny Exp $

--- src/inspector_agent.cc.orig	2017-05-30 17:32:13.000000000 +0000
+++ src/inspector_agent.cc
@@ -96,7 +96,7 @@ static int RegisterDebugSignalHandler()
   // Don't shrink the thread's stack on FreeBSD.  Said platform decided to
   // follow the pthreads specification to the letter rather than in spirit:
   // https://lists.freebsd.org/pipermail/freebsd-current/2014-March/048885.html
-#ifndef __FreeBSD__
+#if defined(__FreeBSD__) && !defined(__NetBSD__) 
   CHECK_EQ(0, pthread_attr_setstacksize(&attr, PTHREAD_STACK_MIN));
 #endif  // __FreeBSD__
   CHECK_EQ(0, pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED));
