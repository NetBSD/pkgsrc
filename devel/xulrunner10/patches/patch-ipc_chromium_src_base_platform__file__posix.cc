$NetBSD: patch-ipc_chromium_src_base_platform__file__posix.cc,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- ipc/chromium/src/base/platform_file_posix.cc.orig	2012-03-09 22:20:16.000000000 +0000
+++ ipc/chromium/src/base/platform_file_posix.cc
@@ -10,6 +10,7 @@
 #ifdef ANDROID
 #include <linux/stat.h>
 #endif
+#include <sys/stat.h> /* for S_IRUSR */
 
 #include "base/logging.h"
 #include "base/string_util.h"
