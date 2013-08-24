$NetBSD: patch-ipc_chromium_src_base_file__util.cc,v 1.1.2.2 2013/08/24 19:45:15 tron Exp $

--- ipc/chromium/src/base/file_util.cc.orig	2013-06-18 18:47:18.000000000 +0000
+++ ipc/chromium/src/base/file_util.cc
@@ -194,7 +194,7 @@ bool ReadFileToString(const FilePath& pa
 FILE* CreateAndOpenTemporaryFile(FilePath* path) {
   FilePath directory;
   if (!GetTempDir(&directory))
-    return false;
+    return NULL;
 
   return CreateAndOpenTemporaryFileInDir(directory, path);
 }
