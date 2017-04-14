$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.1 2017/04/14 16:38:54 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-05-09 14:08:57.000000000 +0200
+++ cmake/PluginConfigure.cmake	2017-04-14 17:00:15.000000000 +0200
@@ -34,11 +34,13 @@
  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
+ IF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+  ADD_DEFINITIONS( "-fPIC")
+ ENDIF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
+ if(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
