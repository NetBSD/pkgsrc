$NetBSD: patch-build__files_cmake_Modules_FindOpenColorIO.cmake,v 1.1 2024/08/09 03:40:22 ryoon Exp $

* Do not find libminizip.so when archivers/minizip is installed.
  Fix build failure '-lminizip not found'.

--- build_files/cmake/Modules/FindOpenColorIO.cmake.orig	2024-08-08 08:01:23.121270460 +0000
+++ build_files/cmake/Modules/FindOpenColorIO.cmake
@@ -24,7 +24,7 @@ SET(_opencolorio_FIND_COMPONENTS
   yaml-cpp
   expat
   pystring
-  minizip
+  minizip-ng
 )
 
 SET(_opencolorio_SEARCH_DIRS
