$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.2 2016/05/21 10:50:41 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-04-13 08:28:11.000000000 +0200
+++ cmake/PluginConfigure.cmake	2016-05-21 12:20:47.579936156 +0200
@@ -45,11 +45,13 @@
 #  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+ IF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
+   SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
+   ADD_DEFINITIONS( "-fPIC")
+ ENDIF(CMAKE_SYSTEM_NAME MATCHES ".*Linux")
+ IF(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
