$NetBSD: patch-lib_remote_jsonrpcconnection.cpp,v 1.1 2025/02/19 18:02:21 wiz Exp $

Support boost 1.87.
https://github.com/Icinga/icinga2/pull/10278

--- lib/remote/jsonrpcconnection.cpp.orig	2025-02-05 14:12:30.000000000 +0000
+++ lib/remote/jsonrpcconnection.cpp
@@ -212,7 +212,7 @@ void JsonRpcConnection::SendMessage(cons
 
 	Ptr keepAlive (this);
 
-	m_IoStrand.post([this, keepAlive, message]() { SendMessageInternal(message); });
+	boost::asio::post(m_IoStrand, [this, keepAlive, message] { SendMessageInternal(message); });
 }
 
 void JsonRpcConnection::SendRawMessage(const String& message)
@@ -223,7 +223,7 @@ void JsonRpcConnection::SendRawMessage(c
 
 	Ptr keepAlive (this);
 
-	m_IoStrand.post([this, keepAlive, message]() {
+	boost::asio::post(m_IoStrand, [this, keepAlive, message] {
 		if (m_ShuttingDown) {
 			return;
 		}
