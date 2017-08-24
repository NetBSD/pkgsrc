$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.4 2017/08/24 13:01:33 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2017-07-07 00:58:37.000000000 +0200
+++ cmake/PluginConfigure.cmake	2017-08-24 11:45:09.253375656 +0200
@@ -46,9 +46,9 @@
  ENDIF(PROFILING)
 
  IF(NOT APPLE)
-  SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+  SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
  ELSE(NOT APPLE)
-  SET( CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+  SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
  ENDIF(NOT APPLE)
 
 
