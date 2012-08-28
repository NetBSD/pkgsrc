$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.4 2012/08/28 12:42:01 ryoon Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/base/file_util_posix.cc.orig	2012-08-08 20:20:07.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -31,7 +31,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef OS_LINUX
 #define stat64 stat
 #endif
 
