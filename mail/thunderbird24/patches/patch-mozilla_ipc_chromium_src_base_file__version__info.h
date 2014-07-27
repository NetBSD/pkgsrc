$NetBSD: patch-mozilla_ipc_chromium_src_base_file__version__info.h,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_version_info.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_version_info.h
@@ -86,7 +86,7 @@ class FileVersionInfo {
   explicit FileVersionInfo(NSBundle *bundle);
 
   NSBundle *bundle_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   FileVersionInfo();
 #endif
 
