$NetBSD: patch-src_cmake_modules_FindOpenJpeg.cmake,v 1.1 2014/04/07 12:15:55 ryoon Exp $

--- src/cmake/modules/FindOpenJpeg.cmake.orig	2014-04-03 06:08:57.000000000 +0000
+++ src/cmake/modules/FindOpenJpeg.cmake
@@ -78,7 +78,7 @@ if (OPENJPEG_HOME)
        ${OPENJPEG_HOME}/lib64)
   set (OpenJpeg_include_paths
        ${OpenJpeg_include_paths}
-       ${OPENJPEG_HOME}/include)
+       ${OPENJPEG_HOME}/include/openjpeg-1.5)
 endif()
 
 
