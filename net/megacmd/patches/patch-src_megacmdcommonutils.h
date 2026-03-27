$NetBSD: patch-src_megacmdcommonutils.h,v 1.2 2026/03/27 11:06:04 kikadf Exp $

* BSDs use the functions of linux

--- src/megacmdcommonutils.h.orig	2026-03-21 08:58:56.000000000 +0000
+++ src/megacmdcommonutils.h
@@ -347,7 +347,8 @@ void sleepMilliSeconds(long microseconds
  */
 bool isValidEmail(const std::string &email);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
 std::string getCurrentExecPath();
 #endif
 
