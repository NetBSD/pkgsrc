$NetBSD: patch-cmake_OpenCVFindOpenEXR.cmake,v 1.1 2021/07/08 21:27:39 markd Exp $

openexr3

--- cmake/OpenCVFindOpenEXR.cmake.orig	2019-12-19 15:16:47.000000000 +0000
+++ cmake/OpenCVFindOpenEXR.cmake
@@ -9,6 +9,14 @@
 # OPENEXR_LIBRARIES = libraries that are needed to use OpenEXR.
 #
 
+find_package(OpenEXR 3.0 CONFIG QUIET)
+if(TARGET OpenEXR::OpenEXR)
+    SET(OPENEXR_FOUND TRUE)
+    SET(OPENEXR_LIBRARIES OpenEXR::OpenEXR)
+    SET(OPENEXR_VERSION ${OpenEXR_VERSION})
+    return()
+endif()
+
 SET(OPENEXR_LIBRARIES "")
 SET(OPENEXR_LIBSEARCH_SUFFIXES "")
 file(TO_CMAKE_PATH "$ENV{ProgramFiles}" ProgramFiles_ENV_PATH)
