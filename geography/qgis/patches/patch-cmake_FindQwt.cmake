$NetBSD: patch-cmake_FindQwt.cmake,v 1.3 2021/03/01 01:06:30 gdt Exp $

Force pkgsrc path only rather than looking in a large number of random
places.

Not yet reported upstream.

--- cmake/FindQwt.cmake.orig	2021-02-19 12:09:21.000000000 +0000
+++ cmake/FindQwt.cmake
@@ -17,11 +17,7 @@ set(QWT_LIBRARY_NAMES qwt-qt5 qwt6-qt5 q
 find_library(QWT_LIBRARY
   NAMES ${QWT_LIBRARY_NAMES}
   PATHS
-    /usr/lib
-    /usr/local/lib
-    /usr/local/lib/qt5
-    "$ENV{LIB_DIR}/lib"
-    "$ENV{LIB}"
+    "${QWT_DIR}/lib"
 )
 
 set(_qwt_fw)
@@ -31,13 +27,7 @@ endif()
 
 FIND_PATH(QWT_INCLUDE_DIR NAMES qwt.h PATHS
   "${_qwt_fw}/Headers"
-  /usr/include
-  /usr/include/qt5
-  /usr/local/include
-  /usr/local/include/qt5
-  "$ENV{LIB_DIR}/include"
-  "$ENV{INCLUDE}"
-  PATH_SUFFIXES qwt-qt5 qwt qwt6
+  "${QWT_DIR}/include"
 )
 
 IF (QWT_INCLUDE_DIR AND QWT_LIBRARY)
