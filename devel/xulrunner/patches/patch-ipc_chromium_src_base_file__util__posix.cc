$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.5 2012/08/28 23:27:10 ryoon Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2012-08-24 22:55:37.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -31,7 +31,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef HAVE_STAT64
 #define stat64 stat
 #endif
 
