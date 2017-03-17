$NetBSD: patch-iwyu__location__util.h,v 1.1 2017/03/17 22:39:31 adam Exp $

Fix for LLVM 4.0.0.

--- iwyu_location_util.h.orig	2017-03-17 20:33:46.000000000 +0000
+++ iwyu_location_util.h
@@ -78,8 +78,7 @@ inline bool IsBuiltinFile(const clang::F
 // IsBuiltinOrCommandLineFile(file) returns true if it's either of the
 // two cases.
 inline bool IsBuiltinOrCommandLineFile(const clang::FileEntry* file) {
-  return IsBuiltinFile(file) ||
-         (strcmp(file->getName(), "<command line>") == 0);
+  return IsBuiltinFile(file) || file->getName().equals("<command line>");
 }
 
 // When macro args are concatenated e.g. '#define CAT(A, B) A##B', their
