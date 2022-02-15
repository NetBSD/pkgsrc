$NetBSD: patch-cmake_FindQwt.cmake,v 1.4 2022/02/15 12:59:21 gdt Exp $

Force pkgsrc path only rather than looking in a large number of random
places.

Not yet reported upstream; it's not clear how to merge how we want to
handle this and upstream's approach.

--- cmake/FindQwt.cmake.orig	2022-01-14 12:06:34.000000000 +0000
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
-  PATH_SUFFIXES qwt-qt5 qwt qwt6 qt5/qwt
+  "${QWT_DIR}/include"
 )
 
 IF (QWT_INCLUDE_DIR AND QWT_LIBRARY)
