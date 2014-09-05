$NetBSD: patch-src_xmlrpcpp_XmlRpcServer.cpp,v 1.3 2014/09/05 07:29:28 mef Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/xmlrpcpp/XmlRpcServer.cpp.orig	2013-05-03 14:42:36.000000000 +0000
+++ src/xmlrpcpp/XmlRpcServer.cpp
@@ -481,7 +481,7 @@ XmlRpcServer::generateHeader(std::string
     "Content-length: ";
 
   char buffLen[40];
-  sprintf(buffLen,"%"PRIuSZ"\r\n\r\n", body.size());
+  sprintf(buffLen,"%" PRIuSZ "\r\n\r\n", body.size());
 
   return header + buffLen;
 }
