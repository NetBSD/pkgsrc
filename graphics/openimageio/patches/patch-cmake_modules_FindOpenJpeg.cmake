$NetBSD: patch-cmake_modules_FindOpenJpeg.cmake,v 1.1 2012/12/08 22:47:41 adam Exp $

Where to find openjpeg includes.

--- cmake/modules/FindOpenJpeg.cmake.orig	2012-12-07 21:44:03.000000000 +0000
+++ cmake/modules/FindOpenJpeg.cmake
@@ -76,7 +76,7 @@ if (OPENJPEG_HOME)
        ${OPENJPEG_HOME}/lib64)
   set (OpenJpeg_include_paths
        ${OpenJpeg_include_paths}
-       ${OPENJPEG_HOME}/include)
+       ${OPENJPEG_HOME}/include/openjpeg-1.5)
 endif()
 
 
