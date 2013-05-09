$NetBSD: patch-src_protocol_handshake.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/protocol/handshake.cc.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/protocol/handshake.cc
@@ -55,6 +55,12 @@
 #include "handshake.h"
 #include "handshake_manager.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#else
+using std::tr1::bind;
+#endif
+
 namespace torrent {
 
 const char* Handshake::m_protocol = "BitTorrent protocol";
@@ -100,7 +106,7 @@ Handshake::Handshake(SocketFd fd, Handsh
   m_writeBuffer.reset();      
 
   m_taskTimeout.clear_time();
-  m_taskTimeout.slot() = std::tr1::bind(&HandshakeManager::receive_timeout, m, this);
+  m_taskTimeout.slot() = bind(&HandshakeManager::receive_timeout, m, this);
 }
 
 Handshake::~Handshake() {
