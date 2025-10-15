$NetBSD: patch-plugin_x_client_xprotocol__impl.cc,v 1.1 2025/10/15 03:52:37 jnemeth Exp $

--- plugin/x/client/xprotocol_impl.cc.orig	2025-09-26 13:01:59.742201211 +0000
+++ plugin/x/client/xprotocol_impl.cc
@@ -782,7 +782,7 @@ std::unique_ptr<XProtocol::Message> Prot
   DBUG_LOG("debug", "Deserialize message: " << ret_val->GetTypeName());
   if (!ret_val->ParseFromCodedStream(input_stream)) {
     std::string error_message(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-    error_message += "Name:" + ret_val->GetTypeName() + ", ";
+    error_message += "Name:" + std::string(ret_val->GetTypeName()) + ", ";
     error_message += ret_val->InitializationErrorString();
     *out_error = XError(CR_MALFORMED_PACKET, error_message);
 
@@ -816,7 +816,7 @@ std::unique_ptr<XProtocol::Message> Prot
 
   if (!ret_val->IsInitialized()) {
     std::string err(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-    err += "Name:" + ret_val->GetTypeName() + ", ";
+    err += "Name:" + std::string(ret_val->GetTypeName()) + ", ";
     err += ret_val->InitializationErrorString();
     *out_error = XError(CR_MALFORMED_PACKET, err);
 
@@ -1122,7 +1122,7 @@ XProtocol::Message *Protocol_impl::recv_
 
     if (!m_compressed.ParseFromCodedStream(&cis)) {
       std::string error_message(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-      error_message += "Name:" + m_compressed.GetTypeName() + ", ";
+      error_message += "Name:" + std::string(m_compressed.GetTypeName()) + ", ";
       error_message += m_compressed.InitializationErrorString();
       *out_error = XError(CR_MALFORMED_PACKET, error_message);
       return nullptr;
