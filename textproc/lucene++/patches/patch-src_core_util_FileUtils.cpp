$NetBSD: patch-src_core_util_FileUtils.cpp,v 1.1 2024/04/21 17:28:32 adam Exp $

Fix build with newer boost.

--- src/core/util/FileUtils.cpp.orig	2024-04-21 17:22:39.775305801 +0000
+++ src/core/util/FileUtils.cpp
@@ -5,7 +5,7 @@
 /////////////////////////////////////////////////////////////////////////////
 
 #include "LuceneInc.h"
-#include <boost/filesystem/convenience.hpp>
+#include <boost/filesystem/directory.hpp>
 #include <boost/filesystem/operations.hpp>
 #include <boost/filesystem/path.hpp>
 #include "LuceneThread.h"
@@ -128,12 +128,12 @@ String joinPath(const String& path, cons
 }
 
 String extractPath(const String& path) {
-    boost::filesystem::wpath parentPath(path.c_str());
+    boost::filesystem::path parentPath(path.c_str());
     return parentPath.parent_path().wstring().c_str();
 }
 
 String extractFile(const String& path) {
-    boost::filesystem::wpath fileName(path.c_str());
+    boost::filesystem::path fileName(path.c_str());
     return fileName.filename().wstring().c_str();
 }
 
