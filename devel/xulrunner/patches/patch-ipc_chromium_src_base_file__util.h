$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.2 2012/03/06 12:34:09 ryoon Exp $

--- ipc/chromium/src/base/file_util.h.orig	2011-12-20 23:28:19.000000000 +0000
+++ ipc/chromium/src/base/file_util.h
@@ -16,8 +16,8 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
-#include <fts.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
