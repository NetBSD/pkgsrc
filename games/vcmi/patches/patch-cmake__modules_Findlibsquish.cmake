$NetBSD: patch-cmake__modules_Findlibsquish.cmake,v 1.1 2026/05/07 17:16:19 adam Exp $

Use correct include path for newer libsquish.

--- cmake_modules/Findlibsquish.cmake.orig	2026-05-07 05:20:01.995388890 +0000
+++ cmake_modules/Findlibsquish.cmake
@@ -10,7 +10,7 @@
 find_path(
     LIBSQUISH_INCLUDE_DIR
-    squish.h
+    squish/squish.h
     PATH_SUFFIXES squish
     PATHS
         /usr/include
         /usr/local/include
