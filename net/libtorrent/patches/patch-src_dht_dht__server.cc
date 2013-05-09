$NetBSD: patch-src_dht_dht__server.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/dht/dht_server.cc.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/dht/dht_server.cc
@@ -56,6 +56,12 @@
 
 #include "manager.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
+
 namespace torrent {
 
 const char* DhtServer::queries[] = {
@@ -154,7 +160,7 @@ DhtServer::start(int port) {
     throw;
   }
 
-  m_taskTimeout.slot() = std::tr1::bind(&DhtServer::receive_timeout, this);
+  m_taskTimeout.slot() = bind(&DhtServer::receive_timeout, this);
 
   m_uploadNode.set_list_iterator(m_uploadThrottle->end());
   m_uploadNode.slot_activate(rak::make_mem_fun(static_cast<SocketBase*>(this), &SocketBase::receive_throttle_up_activate));
