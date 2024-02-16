$NetBSD: patch-cmake_zlib.cmake,v 1.2 2024/02/16 22:01:10 adam Exp $

Fix zlib detection.

--- cmake/zlib.cmake.orig	2023-12-12 18:09:36.000000000 +0000
+++ cmake/zlib.cmake
@@ -67,6 +67,8 @@ FUNCTION(FIND_SYSTEM_ZLIB)
     SET(ZLIB_VERSION ${ZLIB_VERSION} PARENT_SCOPE)
     # For EXTRACT_LINK_LIBRARIES
     SET(zlib_SYSTEM_LINK_FLAGS "-lz" CACHE STRING "Link flag for zlib")
+  ELSE()
+    MESSAGE(FATAL_ERROR "Cannot find system zlib libraries.")
   ENDIF()
 ENDFUNCTION(FIND_SYSTEM_ZLIB)
 
@@ -121,9 +123,7 @@ MACRO (MYSQL_CHECK_ZLIB)
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
