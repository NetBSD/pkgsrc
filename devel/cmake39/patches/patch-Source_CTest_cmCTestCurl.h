$NetBSD: patch-Source_CTest_cmCTestCurl.h,v 1.1 2025/10/02 11:49:44 nia Exp $

* Fix build with curl-8.16.0.
  From: https://gitlab.kitware.com/cmake/cmake/-/commit/c92268f91b30e6d52b82d1ffad227cadafcf4dbf

--- Source/CTest/cmCTestCurl.h.orig	2025-10-02 10:25:07.633754600 +0000
+++ Source/CTest/cmCTestCurl.h
@@ -42,7 +42,7 @@ private:
   std::vector<std::string> HttpHeaders;
   std::string HTTPProxyAuth;
   std::string HTTPProxy;
-  curl_proxytype HTTPProxyType;
+  long HTTPProxyType;
   bool VerifyHostOff;
   bool VerifyPeerOff;
   bool UseHttp10;
