$NetBSD: patch-cmake_Modules_FindQhull.cmake,v 1.1 2021/05/03 06:25:11 thor Exp $

Support current qhull (from PR 4540).

--- cmake/Modules/FindQhull.cmake.orig	2020-08-14 12:23:03.000000000 +0000
+++ cmake/Modules/FindQhull.cmake
@@ -9,14 +9,14 @@
 # If QHULL_USE_STATIC is specified then look for static libraries ONLY else
 # look for shared ones
 
-set(QHULL_MAJOR_VERSION 6)
+set(QHULL_MAJOR_VERSION 8)
 
 if(QHULL_USE_STATIC)
   set(QHULL_RELEASE_NAME qhullstatic)
   set(QHULL_DEBUG_NAME qhullstatic_d)
 else()
-  set(QHULL_RELEASE_NAME qhull_p qhull${QHULL_MAJOR_VERSION} qhull)
-  set(QHULL_DEBUG_NAME qhull_p_d qhull${QHULL_MAJOR_VERSION}_d qhull_d${QHULL_MAJOR_VERSION} qhull_d)
+  set(QHULL_RELEASE_NAME qhull_r qhull${QHULL_MAJOR_VERSION} qhull)
+  set(QHULL_DEBUG_NAME qhull_r_d qhull${QHULL_MAJOR_VERSION}_d qhull_d${QHULL_MAJOR_VERSION} qhull_d)
 endif()
 
 find_file(QHULL_HEADER
