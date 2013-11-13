$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util_posix.cc.orig	2013-06-20 16:39:04.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util_posix.cc
@@ -33,7 +33,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef HAVE_STAT64
 #define stat64 stat
 #endif
 
@@ -392,7 +392,7 @@ bool CreateTemporaryFileName(FilePath* p
 FILE* CreateAndOpenTemporaryShmemFile(FilePath* path) {
   FilePath directory;
   if (!GetShmemTempDir(&directory))
-    return false;
+    return NULL;
 
   return CreateAndOpenTemporaryFileInDir(directory, path);
 }
