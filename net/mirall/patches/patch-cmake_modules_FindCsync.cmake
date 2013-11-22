$NetBSD: patch-cmake_modules_FindCsync.cmake,v 1.1 2013/11/22 12:11:49 ryoon Exp $

* Use ocsync from outside of its source directory

--- cmake/modules/FindCsync.cmake.orig	2013-10-21 12:05:25.000000000 +0000
+++ cmake/modules/FindCsync.cmake
@@ -1,14 +1,13 @@
 
 IF( DEFINED CSYNC_BUILD_PATH )
-  SET(CSYNC_LIBRARY_PATH ${CSYNC_BUILD_PATH})
   SET(CSYNC_BINARY_DIR ${CSYNC_BUILD_PATH})
 
   IF(WIN32)
     SET(CSYNC_LIBRARY ${CSYNC_BUILD_PATH}/src/libocsync.dll)
   ELSEIF( APPLE )
-    SET(CSYNC_LIBRARY ${CSYNC_BUILD_PATH}/src/libocsync.dylib)
+    SET(CSYNC_LIBRARY ${CSYNC_LIBRARY_PATH}/libocsync.dylib)
   ELSE()
-    SET(CSYNC_LIBRARY ${CSYNC_BUILD_PATH}/src/libocsync.so)
+    SET(CSYNC_LIBRARY ${CSYNC_LIBRARY_PATH}/libocsync.so)
   ENDIF()
 ELSE()
   FIND_LIBRARY(CSYNC_LIBRARY NAMES ocsync HINTS $ENV{CSYNC_DIR})
