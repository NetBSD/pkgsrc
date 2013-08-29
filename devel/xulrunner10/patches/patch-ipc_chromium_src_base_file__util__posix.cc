$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.2 2013/08/29 12:56:15 joerg Exp $

--- ipc/chromium/src/base/file_util_posix.cc.orig	2013-01-03 17:43:14.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
@@ -31,7 +31,7 @@
 #include "base/time.h"
 
 // FreeBSD/OpenBSD lacks stat64, but its stat handles files >2GB just fine
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#ifndef __linux__
 #define stat64 stat
 #endif
 
@@ -390,7 +390,7 @@ bool CreateTemporaryFileName(FilePath* p
 FILE* CreateAndOpenTemporaryShmemFile(FilePath* path) {
   FilePath directory;
   if (!GetShmemTempDir(&directory))
-    return false;
+    return NULL;
 
   return CreateAndOpenTemporaryFileInDir(directory, path);
 }
