$NetBSD: patch-base_const.h,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- base/const.h.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/const.h
@@ -146,7 +146,7 @@ const char kMozcTool[] = "mozc_tool";
 #ifdef MOZC_SERVER_DIRECTORY
 const char kMozcServerDirectory[] = MOZC_SERVER_DIRECTORY;
 #else
-const char kMozcServerDirectory[] = "/usr/lib/mozc";
+const char kMozcServerDirectory[] = "@PREFIX@/libexec";
 #endif  // MOZC_SERVER_DIRECTORY
 #ifdef OS_ANDROID
 #ifndef MOZC_ANDROID_APPLICATION_ID
