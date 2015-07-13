$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util.h,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2014-07-18 00:05:24.000000000 +0000
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
 
