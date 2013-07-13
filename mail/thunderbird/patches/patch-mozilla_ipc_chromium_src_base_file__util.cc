$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util.cc,v 1.1 2013/07/13 19:33:19 joerg Exp $

--- mozilla/ipc/chromium/src/base/file_util.cc.orig	2013-07-12 14:40:54.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.cc
@@ -194,7 +194,7 @@ bool ReadFileToString(const FilePath& pa
 FILE* CreateAndOpenTemporaryFile(FilePath* path) {
   FilePath directory;
   if (!GetTempDir(&directory))
-    return false;
+    return NULL;
 
   return CreateAndOpenTemporaryFileInDir(directory, path);
 }
