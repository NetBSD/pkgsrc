$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.6 2018/08/27 15:54:09 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2018-07-18 10:14:19.000000000 +0200
+++ cmake/PluginConfigure.cmake	2018-08-27 15:38:00.730541824 +0200
@@ -69,9 +69,9 @@
   ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_DEPRECATE)
 ELSE(MSVC)
   IF(NOT APPLE)
-    SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
   ELSE(NOT APPLE)
-    SET( CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
   ENDIF(NOT APPLE) 
 ENDIF(MSVC)
 
