$NetBSD: patch-src_thread.cpp,v 1.1 2016/04/03 00:01:30 kamil Exp $

--- src/thread.cpp.orig	2015-11-04 08:55:13.000000000 +0000
+++ src/thread.cpp
@@ -131,6 +131,10 @@ void zmq::thread_t::setSchedulingParamet
         policy = schedulingPolicy_;
     }
 
+#ifdef __NetBSD__
+    if(policy == SCHED_OTHER) param.sched_priority = -1;
+#endif
+
     rc = pthread_setschedparam(descriptor, policy, &param);
     posix_assert (rc);
 #endif
