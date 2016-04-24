$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.1 2016/04/24 10:23:38 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-04-13 23:56:21.000000000 +0200
+++ cmake/PluginConfigure.cmake	2016-04-15 16:25:56.000000000 +0200
@@ -40,11 +40,9 @@
  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O0 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+ IF(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
