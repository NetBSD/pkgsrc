$NetBSD: patch-libpurple_thriftclient.cpp,v 1.1 2018/03/16 21:06:31 scole Exp $

std::make_shared does not seem to compile on NetBSD so use boost::make_shared
	
--- libpurple/thriftclient.cpp.orig	2018-02-21 13:01:04.000000000 -0800
+++ libpurple/thriftclient.cpp		2018-03-16 09:45:17.000000000 -0700
@@ -8,11 +8,11 @@
 
 ThriftClient::ThriftClient(PurpleAccount *acct, PurpleConnection *conn, std::string path)
     : line::TalkServiceClient(
-        std::make_shared<apache::thrift::protocol::TCompactProtocol>(
-            std::make_shared<LineHttpTransport>(acct, conn, LINE_THRIFT_SERVER, 443, true))),
+        boost::make_shared<apache::thrift::protocol::TCompactProtocol>(
+            boost::make_shared<LineHttpTransport>(acct, conn, LINE_THRIFT_SERVER, 443, true))),
     path(path)
 {
-    http = std::static_pointer_cast<LineHttpTransport>(getInputProtocol()->getTransport());
+    http = boost::static_pointer_cast<LineHttpTransport>(getInputProtocol()->getTransport());
 }
 
 void ThriftClient::set_path(std::string path) {
