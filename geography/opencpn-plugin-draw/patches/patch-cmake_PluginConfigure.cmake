$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.3 2017/04/14 16:28:40 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2017-03-12 09:27:12.000000000 +0100
+++ cmake/PluginConfigure.cmake	2017-04-14 13:29:02.000000000 +0200
@@ -45,11 +45,13 @@
 #  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
+ IF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
   SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+  ADD_DEFINITIONS( "-fPIC")
+ ENDIF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
+ IF(APPLE)
   SET( CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 
 ENDIF(NOT MSVC)
