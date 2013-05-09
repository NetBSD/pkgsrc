$NetBSD: patch-src_core_dht__manager.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/dht_manager.cc.orig	2013-05-03 22:44:37.000000000 +0000
+++ src/core/dht_manager.cc
@@ -54,6 +54,14 @@
 #include "download_store.h"
 #include "manager.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace core {
 
 const char* DhtManager::dht_settings[dht_settings_num] = { "disable", "off", "auto", "on" };
@@ -114,7 +122,7 @@ DhtManager::start_dht() {
     torrent::dht_manager()->start(port);
     torrent::dht_manager()->reset_statistics();
 
-    m_updateTimeout.slot() = std::tr1::bind(&DhtManager::update, this);
+    m_updateTimeout.slot() = bind(&DhtManager::update, this);
     priority_queue_insert(&taskScheduler, &m_updateTimeout, (cachedTime + rak::timer::from_seconds(60)).round_seconds());
 
     m_dhtPrevCycle = 0;
@@ -197,7 +205,7 @@ DhtManager::update() {
         break;
       
     if (itr == end) {
-      m_stopTimeout.slot() = std::tr1::bind(&DhtManager::stop_dht, this);
+      m_stopTimeout.slot() = bind(&DhtManager::stop_dht, this);
       priority_queue_insert(&taskScheduler, &m_stopTimeout, (cachedTime + rak::timer::from_seconds(15 * 60)).round_seconds());
     }
   }
