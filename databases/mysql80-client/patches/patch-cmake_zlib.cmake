$NetBSD: patch-cmake_zlib.cmake,v 1.1 2023/05/23 21:01:12 adam Exp $

Fix zlib detection.

--- cmake/zlib.cmake.orig	2023-05-23 08:13:52.000000000 +0000
+++ cmake/zlib.cmake
@@ -60,6 +60,8 @@ FUNCTION(FIND_SYSTEM_ZLIB)
       TARGET_INCLUDE_DIRECTORIES(zlib_interface SYSTEM INTERFACE
         ${ZLIB_INCLUDE_DIR})
     ENDIF()
+  ELSE()
+    MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
   ENDIF()
 ENDFUNCTION(FIND_SYSTEM_ZLIB)
 
@@ -114,9 +116,7 @@ MACRO (MYSQL_CHECK_ZLIB)
     MYSQL_USE_BUNDLED_ZLIB()
   ELSEIF(WITH_ZLIB STREQUAL "system")
     FIND_SYSTEM_ZLIB()
-    IF(NOT ZLIB_FOUND)
-      MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
-    ENDIF()
+    FIND_ZLIB_VERSION(${ZLIB_INCLUDE_DIR})
   ELSE()
     RESET_ZLIB_VARIABLES()
     MESSAGE(FATAL_ERROR "WITH_ZLIB must be bundled or system")
