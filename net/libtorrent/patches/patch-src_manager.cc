$NetBSD: patch-src_manager.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/manager.cc.orig	2012-04-20 06:41:42.000000000 +0000
+++ src/manager.cc
@@ -59,7 +59,13 @@
 
 #include "manager.h"
 
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 namespace torrent {
 
@@ -83,12 +89,12 @@ Manager::Manager() :
 
   m_hashQueue = new HashQueue(&m_main_thread_disk);
   m_hashQueue->slot_has_work() =
-    tr1::bind(&thread_base::send_event_signal,
+    bind(&thread_base::send_event_signal,
               &m_main_thread_main,
-              m_main_thread_main.signal_bitfield()->add_signal(tr1::bind(&HashQueue::work, m_hashQueue)),
-              tr1::placeholders::_1);
+              m_main_thread_main.signal_bitfield()->add_signal(bind(&HashQueue::work, m_hashQueue)),
+              STD_PLACEHOLDERS::_1);
 
-  m_taskTick.slot() = std::tr1::bind(&Manager::receive_tick, this);
+  m_taskTick.slot() = bind(&Manager::receive_tick, this);
 
   priority_queue_insert(&taskScheduler, &m_taskTick, cachedTime.round_seconds());
 
