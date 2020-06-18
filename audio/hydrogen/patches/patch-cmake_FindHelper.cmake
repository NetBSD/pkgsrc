$NetBSD: patch-cmake_FindHelper.cmake,v 1.1 2020/06/18 12:57:49 nia Exp $

No peeking outside of buildlink.

--- cmake/FindHelper.cmake.orig	2020-06-07 18:13:40.000000000 +0000
+++ cmake/FindHelper.cmake
@@ -31,13 +31,15 @@ macro(FIND_HELPER prefix pkg_name header
         # find_path
         find_path(${prefix}_INCLUDE_DIRS
             NAMES ${header}
-            HINTS ${PC_${prefix}_INCLUDEDIR} ${PC_${prefix}_INCLUDE_DIRS}
+            HINTS ${PC_${prefix}_INCLUDEDIR} ${PC_${prefix}_INCLUDE_DIRS} /usr/include
+            NO_DEFAULT_PATH
             ENV ${prefix}_INCLUDE
             )
         # find_library
         find_library(${prefix}_LIBRARIES
             NAMES ${lib}
-            HINTS ${PC_${prefix}_LIBDIR} ${PC_${prefix}_LIBRARY_DIRS}
+            HINTS ${PC_${prefix}_LIBDIR} ${PC_${prefix}_LIBRARY_DIRS} /usr/lib
+            NO_DEFAULT_PATH
             ENV ${prefix}_PATH
             )
         include(FindPackageHandleStandardArgs)
