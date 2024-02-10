$NetBSD: patch-base_file_recursive.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- base/file/recursive.cc.orig	2023-10-26 12:00:50.000000000 +0000
+++ base/file/recursive.cc
@@ -105,7 +105,8 @@ void UnlinkFileOrLog(const char *path) {
 }  // namespace
 
 #if (defined(__linux__) && !defined(__ANDROID__)) || \
-    (defined(TARGET_OS_OSX) && TARGET_OS_OSX)
+    (defined(TARGET_OS_OSX) && TARGET_OS_OSX) || \
+    defined(__NetBSD__)
 
 absl::Status DeleteRecursively(const zstring_view path) {
   // fts is not POSIX, but it's available on both Linux and MacOS.
