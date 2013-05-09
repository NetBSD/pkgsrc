$NetBSD: patch-src_dht_dht__router.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/dht/dht_router.cc.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/dht/dht_router.cc
@@ -51,6 +51,12 @@
 #include "dht_tracker.h"
 #include "dht_transaction.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
+
 namespace torrent {
 
 HashString DhtRouter::zero_id;
@@ -131,7 +137,7 @@ DhtRouter::start(int port) {
   m_server.start(port);
 
   // Set timeout slot and schedule it to be called immediately for initial bootstrapping if necessary.
-  m_taskTimeout.slot() = std::tr1::bind(&DhtRouter::receive_timeout_bootstrap, this);
+  m_taskTimeout.slot() = bind(&DhtRouter::receive_timeout_bootstrap, this);
   priority_queue_insert(&taskScheduler, &m_taskTimeout, (cachedTime + rak::timer::from_seconds(1)).round_seconds());
 }
 
@@ -410,7 +416,7 @@ DhtRouter::receive_timeout_bootstrap() {
     delete m_contacts;
     m_contacts = NULL;
 
-    m_taskTimeout.slot() = std::tr1::bind(&DhtRouter::receive_timeout, this);
+    m_taskTimeout.slot() = bind(&DhtRouter::receive_timeout, this);
 
     if (!m_numRefresh) {
       // If we're still in the startup, do the usual refreshing too.
