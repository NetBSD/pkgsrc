$NetBSD: patch-plugin_x_client_xprotocol__impl.cc,v 1.1 2025/10/22 07:21:48 jnemeth Exp $

--- plugin/x/client/xprotocol_impl.cc.orig	2025-10-20 03:17:06.101903558 +0000
+++ plugin/x/client/xprotocol_impl.cc
@@ -32,6 +32,7 @@
 #include <iostream>
 #include <limits>
 #include <string>
+#include <string_view>
 
 #include "errmsg.h"     // NOLINT(build/include_subdir)
 #include "my_config.h"  // NOLINT(build/include_subdir)
@@ -782,7 +783,7 @@ std::unique_ptr<XProtocol::Message> Prot
   DBUG_LOG("debug", "Deserialize message: " << ret_val->GetTypeName());
   if (!ret_val->ParseFromCodedStream(input_stream)) {
     std::string error_message(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-    error_message += "Name:" + ret_val->GetTypeName() + ", ";
+    error_message += "Name:" + std::string(ret_val->GetTypeName()) + ", ";
     error_message += ret_val->InitializationErrorString();
     *out_error = XError(CR_MALFORMED_PACKET, error_message);
 
@@ -816,7 +817,7 @@ std::unique_ptr<XProtocol::Message> Prot
 
   if (!ret_val->IsInitialized()) {
     std::string err(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-    err += "Name:" + ret_val->GetTypeName() + ", ";
+    err += "Name:" + std::string(ret_val->GetTypeName()) + ", ";
     err += ret_val->InitializationErrorString();
     *out_error = XError(CR_MALFORMED_PACKET, err);
 
@@ -1122,7 +1123,7 @@ XProtocol::Message *Protocol_impl::recv_
 
     if (!m_compressed.ParseFromCodedStream(&cis)) {
       std::string error_message(ERR_MSG_MESSAGE_NOT_INITIALIZED);
-      error_message += "Name:" + m_compressed.GetTypeName() + ", ";
+      error_message += "Name:" + std::string(m_compressed.GetTypeName()) + ", ";
       error_message += m_compressed.InitializationErrorString();
       *out_error = XError(CR_MALFORMED_PACKET, error_message);
       return nullptr;
