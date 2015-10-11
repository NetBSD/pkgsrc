$NetBSD: patch-src_xmlrpcpp_XmlRpcBase64.h,v 1.2 2015/10/11 03:59:56 mef Exp $

date: 2015-04-28 08:51:52 +0900;  author: joerg;  state: Exp;  commitid: 2iTQbBPEdUwBShjy;
Deal with C++11 user defined string literals. Add missing includes.

--- src/xmlrpcpp/XmlRpcBase64.h.orig	2015-04-27 23:29:49.000000000 +0000
+++ src/xmlrpcpp/XmlRpcBase64.h
@@ -19,6 +19,7 @@
 #define __BASE64_H_INCLUDED__ 1
 
 #include <iterator>
+#include <ios>
 
 static
 int _xmlrpc_base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
