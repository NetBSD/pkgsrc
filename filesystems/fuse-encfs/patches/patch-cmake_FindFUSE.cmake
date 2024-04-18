$NetBSD: patch-cmake_FindFUSE.cmake,v 1.3 2024/04/18 05:36:13 pho Exp $

Use pkg-config for finding FUSE. Don't look for hard-coded paths.

--- cmake/FindFUSE.cmake.orig	2018-04-27 08:52:22.000000000 +0000
+++ cmake/FindFUSE.cmake
@@ -9,21 +9,10 @@ if (FUSE_INCLUDE_DIR)
         SET (FUSE_FIND_QUIETLY TRUE)
 endif (FUSE_INCLUDE_DIR)
 
-if (APPLE)
-    set (FUSE_NAMES libosxfuse.dylib fuse)
-    set (FUSE_SUFFIXES osxfuse fuse)
-else (APPLE)
-    set (FUSE_NAMES fuse refuse)
-    set (FUSE_SUFFIXES fuse refuse)
-endif (APPLE)
-
-# find includes
-find_path (FUSE_INCLUDE_DIR fuse.h
-        PATHS /opt /opt/local /usr/pkg
-        PATH_SUFFIXES ${FUSE_SUFFIXES})
-
-# find lib
-find_library (FUSE_LIBRARIES NAMES ${FUSE_NAMES})
+find_package(PkgConfig REQUIRED)
+pkg_search_module(FUSE REQUIRED fuse)
+set(FUSE_INCLUDE_DIR "${FUSE_INCLUDE_DIRS}")
+set(FUSE_LIBRARIES "${FUSE_LINK_LIBRARIES}")
 
 include ("FindPackageHandleStandardArgs")
 find_package_handle_standard_args ("FUSE" DEFAULT_MSG
