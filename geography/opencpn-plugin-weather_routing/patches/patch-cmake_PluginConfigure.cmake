$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.3 2025/08/19 13:15:38 wiz Exp $

Fix build with cmake 4.

Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2018-06-21 21:28:17.000000000 +0000
+++ cmake/PluginConfigure.cmake
@@ -6,13 +6,6 @@
 
 SET(PLUGIN_SOURCE_DIR .)
 
-# This should be 2.8.0 to have FindGTK2 module
-IF (COMMAND cmake_policy)
-  CMAKE_POLICY(SET CMP0003 OLD)
-  CMAKE_POLICY(SET CMP0005 OLD)
-  CMAKE_POLICY(SET CMP0011 OLD)
-ENDIF (COMMAND cmake_policy)
-
 MESSAGE (STATUS "*** Staging to build ${PACKAGE_NAME} ***")
 
 configure_file(cmake/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h)
@@ -40,9 +33,9 @@ IF(NOT MSVC)
  ENDIF(PROFILING)
 
  IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
  ELSE(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
  ENDIF(NOT APPLE)
 
 ENDIF(NOT MSVC)
