$NetBSD: patch-cmake_zlib.cmake,v 1.3 2024/08/29 14:42:13 ryoon Exp $

Fix zlib detection.

--- cmake/zlib.cmake.orig	2024-08-28 06:19:17.804401172 +0000
+++ cmake/zlib.cmake
@@ -68,6 +68,8 @@ FUNCTION(FIND_SYSTEM_ZLIB)
     SET(ZLIB_VERSION ${ZLIB_VERSION} PARENT_SCOPE)
     # For EXTRACT_LINK_LIBRARIES
     SET(zlib_SYSTEM_LINK_FLAGS "-lz" CACHE STRING "Link flag for zlib")
+  ELSE()
+    MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
   ENDIF()
 ENDFUNCTION(FIND_SYSTEM_ZLIB)
 
@@ -123,9 +125,7 @@ MACRO (MYSQL_CHECK_ZLIB)
     SET(ZLIB_FOUND ON)
   ELSEIF(WITH_ZLIB STREQUAL "system")
     FIND_SYSTEM_ZLIB()
-    IF(NOT ZLIB_FOUND)
-      MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
-    ENDIF()
+    FIND_ZLIB_VERSION(${ZLIB_INCLUDE_DIR})
   ELSE()
     RESET_ZLIB_VARIABLES()
     MESSAGE(FATAL_ERROR "WITH_ZLIB must be bundled or system")
