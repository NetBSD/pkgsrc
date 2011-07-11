$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.1 2011/07/11 12:46:14 tnn Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2011-06-15 21:57:27.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -30,6 +30,9 @@
 #include "base/string_util.h"
 #include "base/time.h"
 
+#ifndef __linux__
+#define stat64 stat
+#endif
 namespace file_util {
 
 #if defined(GOOGLE_CHROME_BUILD)
