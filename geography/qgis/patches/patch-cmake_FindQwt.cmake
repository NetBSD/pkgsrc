$NetBSD: patch-cmake_FindQwt.cmake,v 1.5 2024/05/12 13:47:30 gdt Exp $

Force pkgsrc path only rather than looking in a large number of random
places.

Not yet reported upstream; it's not clear how to merge how we want to
handle this and upstream's approach.

--- cmake/FindQwt.cmake.orig	2024-04-19 12:01:44.000000000 +0000
+++ cmake/FindQwt.cmake
@@ -17,11 +17,7 @@ set(QWT_LIBRARY_NAMES qwt-${QT_VERSION_B
 find_library(QWT_LIBRARY
   NAMES ${QWT_LIBRARY_NAMES}
   PATHS
-    /usr/lib
-    /usr/local/lib
-    /usr/local/lib/${QT_VERSION_BASE_LOWER}
-    "$ENV{LIB_DIR}/lib"
-    "$ENV{LIB}"
+    "${QWT_DIR}/lib"
 )
 
 set(_qwt_fw)
@@ -31,13 +27,7 @@ endif()
 
 FIND_PATH(QWT_INCLUDE_DIR NAMES qwt.h PATHS
   "${_qwt_fw}/Headers"
-  /usr/include
-  /usr/include/${QT_VERSION_BASE_LOWER}
-  /usr/local/include
-  /usr/local/include/${QT_VERSION_BASE_LOWER}
-  "$ENV{LIB_DIR}/include"
-  "$ENV{INCLUDE}"
-  PATH_SUFFIXES qwt-${QT_VERSION_BASE_LOWER} ${QT_VERSION_BASE_LOWER}/qwt qwt qwt6
+  "${QWT_DIR}/include"
 )
 
 IF (QWT_INCLUDE_DIR AND QWT_LIBRARY)
