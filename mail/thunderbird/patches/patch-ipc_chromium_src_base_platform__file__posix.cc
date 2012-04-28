$NetBSD: patch-ipc_chromium_src_base_platform__file__posix.cc,v 1.3 2012/04/28 16:56:58 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_file_posix.cc.orig	2012-04-20 22:40:05.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_file_posix.cc
@@ -10,6 +10,7 @@
 #ifdef ANDROID
 #include <linux/stat.h>
 #endif
+#include <sys/stat.h> /* for S_IRUSR */
 
 #include "base/logging.h"
 #include "base/string_util.h"
