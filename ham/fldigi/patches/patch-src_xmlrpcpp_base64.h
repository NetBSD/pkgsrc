$NetBSD: patch-src_xmlrpcpp_base64.h,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/xmlrpcpp/base64.h.orig	2013-05-03 14:39:47.000000000 +0000
+++ src/xmlrpcpp/base64.h
@@ -10,6 +10,7 @@
 #define __BASE64_H_INCLUDED__ 1
 
 #include <iterator>
+#include <ios>
 
 static
 int _base64Chars[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
