$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.2 2017/08/24 13:01:32 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-07-16 16:24:09.000000000 +0200
+++ cmake/PluginConfigure.cmake	2017-08-24 11:41:35.216982638 +0200
@@ -35,9 +35,9 @@
  ENDIF(PROFILING)
 
  IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
  ELSE(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+  SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
  ENDIF(NOT APPLE)
 
 ENDIF(NOT MSVC)
