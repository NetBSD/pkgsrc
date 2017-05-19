$NetBSD: patch-include_XmlRpcBase64.h,v 1.1 2017/05/19 14:58:02 joerg Exp $

Provide correct header failbit and friends.

--- include/XmlRpcBase64.h.orig	2017-05-19 11:34:22.124616494 +0000
+++ include/XmlRpcBase64.h
@@ -18,6 +18,7 @@
 #if !defined(__BASE64_H_INCLUDED__)
 #define __BASE64_H_INCLUDED__ 1
 
+#include <ios>
 #include <iterator>
 
 static
