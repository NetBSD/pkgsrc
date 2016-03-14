--- plugins/chartdldr_pi/cmake/PluginConfigure.cmake.orig	2016-02-10 17:29:03.000000000 +0100
+++ plugins/chartdldr_pi/cmake/PluginConfigure.cmake	2016-02-10 17:29:36.000000000 +0100
@@ -41,11 +41,9 @@
  ADD_DEFINITIONS( "-Wall -Wno-unused-result -g -O2 -fexceptions" )
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+ IF(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
