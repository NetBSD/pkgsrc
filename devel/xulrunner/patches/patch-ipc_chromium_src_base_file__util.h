$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.3 2012/05/08 19:29:36 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

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
