$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -16,7 +16,9 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
+#if !defined(OS_SOLARIS)
 #include <fts.h>
+#endif
 #include <sys/stat.h>
 #endif
 
@@ -466,7 +468,7 @@ class FileEnumerator {
 #if defined(OS_WIN)
   WIN32_FIND_DATA find_data_;
   HANDLE find_handle_;
-#elif defined(ANDROID)
+#elif defined(ANDROID) || defined(OS_SOLARIS)
   void *fts_;
 #elif defined(OS_POSIX)
   FTS* fts_;
