$NetBSD: patch-plugins_chartdldr_pi_cmake_PluginConfigure.cmake,v 1.2 2016/05/21 10:50:41 bouyer Exp $

--- plugins/chartdldr_pi/cmake/PluginConfigure.cmake.orig	2016-02-03 18:44:17.000000000 +0100
+++ plugins/chartdldr_pi/cmake/PluginConfigure.cmake	2016-05-21 11:07:31.835017011 +0200
@@ -41,11 +41,12 @@
  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
+ IF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+ ENDIF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
+ IF(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
