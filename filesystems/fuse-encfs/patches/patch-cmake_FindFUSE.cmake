$NetBSD: patch-cmake_FindFUSE.cmake,v 1.1 2017/06/19 18:41:39 maya Exp $

Also try to find (netbsd) librefuse

--- cmake/FindFUSE.cmake.orig	2016-09-18 20:16:04.000000000 +0000
+++ cmake/FindFUSE.cmake
@@ -13,8 +13,8 @@ if (APPLE)
     set (FUSE_NAMES libosxfuse.dylib fuse)
     set (FUSE_SUFFIXES osxfuse fuse)
 else (APPLE)
-    set (FUSE_NAMES fuse)
-    set (FUSE_SUFFIXES fuse)
+    set (FUSE_NAMES fuse refuse)
+    set (FUSE_SUFFIXES fuse refuse)
 endif (APPLE)
 
 # find includes
