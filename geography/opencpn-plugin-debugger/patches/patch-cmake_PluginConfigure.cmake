$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.1 2016/10/24 17:58:29 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-07-16 16:24:09.000000000 +0200
+++ cmake/PluginConfigure.cmake	2016-10-24 18:23:38.000000000 +0200
@@ -34,11 +34,13 @@
  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
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
 
