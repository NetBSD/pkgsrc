$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.1 2016/03/14 11:07:59 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2016-02-10 19:43:27.000000000 +0100
+++ cmake/PluginConfigure.cmake	2016-02-10 19:43:46.000000000 +0100
@@ -43,11 +43,9 @@
   ENDIF(DEBUG)
  ENDIF(PROFILING)
 
- IF(NOT APPLE)
-  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
- ELSE(NOT APPLE)
+ IF(APPLE)
   SET(CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
- ENDIF(NOT APPLE)
+ ENDIF(APPLE)
 
 ENDIF(NOT MSVC)
 
