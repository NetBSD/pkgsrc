$NetBSD: patch-ipc_chromium_src_base_file__util.cc,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- ipc/chromium/src/base/file_util.cc.orig	2013-01-03 17:43:14.000000000 +0000
+++ ipc/chromium/src/base/file_util.cc
@@ -194,7 +194,7 @@ bool ReadFileToString(const FilePath& pa
 FILE* CreateAndOpenTemporaryFile(FilePath* path) {
   FilePath directory;
   if (!GetTempDir(&directory))
-    return false;
+    return NULL;
 
   return CreateAndOpenTemporaryFileInDir(directory, path);
 }
