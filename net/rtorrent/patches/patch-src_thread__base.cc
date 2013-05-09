$NetBSD: patch-src_thread__base.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/thread_base.cc.orig	2013-05-03 23:10:27.000000000 +0000
+++ src/thread_base.cc
@@ -53,6 +53,14 @@
 #include "control.h"
 #include "core/manager.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 // Temporarly injected into config.h.
 /* temp hack */
 //#define lt_cacheline_aligned __attribute__((__aligned__(128)))
@@ -109,7 +117,7 @@ public:
 void throw_shutdown_exception() { throw torrent::shutdown_exception(); }
 
 ThreadBase::ThreadBase() {
-  m_taskShutdown.slot() = std::tr1::bind(&throw_shutdown_exception);
+  m_taskShutdown.slot() = std::bind(&throw_shutdown_exception);
 
   m_threadQueue = new thread_queue_hack;
 }
