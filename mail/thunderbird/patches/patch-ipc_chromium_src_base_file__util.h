$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.2 2012/03/10 11:42:38 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2012-02-16 10:25:01.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -16,8 +16,8 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
-#include <fts.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
