$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.5 2018/04/05 15:56:25 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2018-03-02 08:09:23.000000000 +0100
+++ cmake/PluginConfigure.cmake	2018-04-05 17:46:39.601675541 +0200
@@ -40,9 +40,9 @@
  ENDIF(PROFILING)
 
  IF(NOT APPLE)
-  SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+  SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
  ELSE(NOT APPLE)
-  SET( CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+  SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
  ENDIF(NOT APPLE)
 
 ENDIF(NOT MSVC)
