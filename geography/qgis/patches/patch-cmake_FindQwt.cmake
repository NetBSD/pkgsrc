$NetBSD: patch-cmake_FindQwt.cmake,v 1.1 2019/10/29 19:30:11 bouyer Exp $

--- cmake/FindQwt.cmake.orig	2019-10-27 18:10:06.615593553 +0100
+++ cmake/FindQwt.cmake	2019-10-27 18:11:27.844260494 +0100
@@ -17,11 +17,7 @@
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
@@ -31,12 +27,7 @@
 
 FIND_PATH(QWT_INCLUDE_DIR NAMES qwt.h PATHS
   "${_qwt_fw}/Headers"
-  /usr/include
-  /usr/local/include
-  /usr/local/include/qt5
-  "$ENV{LIB_DIR}/include"
-  "$ENV{INCLUDE}"
-  PATH_SUFFIXES qwt-qt5 qwt qwt6
+  "${QWT_DIR}/include"
 )
 
 IF (QWT_INCLUDE_DIR AND QWT_LIBRARY)
