$NetBSD: patch-src_xmlrpcpp_XmlRpcClient.cpp,v 1.3 2014/09/05 07:29:28 mef Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/xmlrpcpp/XmlRpcClient.cpp.orig	2013-05-03 14:41:57.000000000 +0000
+++ src/xmlrpcpp/XmlRpcClient.cpp
@@ -319,7 +319,7 @@ XmlRpcClient::generateHeader(std::string
 
   header += "Content-Type: text/xml\r\nContent-length: ";
 
-  sprintf(buff,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buff,"%" PRIuSZ "\r\n\r\n", body.size());
 
   return header + buff;
 }
