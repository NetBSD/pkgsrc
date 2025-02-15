$NetBSD: patch-src_megacmdcommonutils.h,v 1.1 2025/02/15 07:40:14 wiz Exp $

* BSDs use the functions of linux

--- src/megacmdcommonutils.h.orig	2025-02-07 09:44:39.977015171 +0100
+++ src/megacmdcommonutils.h
@@ -269,7 +269,8 @@ void sleepMilliSeconds(long microseconds
 
 bool isValidEmail(std::string email);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 std::string getCurrentExecPath();
 #endif
 
