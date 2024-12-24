$NetBSD: patch-build__files_cmake_Modules_FindOpenColorIO.cmake,v 1.1 2024/12/24 14:05:17 ryoon Exp $

* Do not find libminizip.so when archivers/minizip is installed.
  Fix build failure '-lminizip not found'.

--- build_files/cmake/Modules/FindOpenColorIO.cmake.orig	2024-12-23 08:16:15.023452199 +0000
+++ build_files/cmake/Modules/FindOpenColorIO.cmake
@@ -29,7 +29,7 @@ set(_opencolorio_FIND_COMPONENTS
   yaml-cpp
   expat
   pystring
-  minizip
+  minizip-ng
 )
 
 set(_opencolorio_SEARCH_DIRS
