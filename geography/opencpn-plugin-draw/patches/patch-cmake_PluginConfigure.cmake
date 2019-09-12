$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.7 2019/09/12 16:54:34 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2019-07-18 09:04:32.000000000 +0200
+++ cmake/PluginConfigure.cmake	2019-09-12 18:28:14.915554652 +0200
@@ -70,9 +70,9 @@
   ADD_DEFINITIONS(-D HAVE_SNPRINTF)
 ELSE(MSVC)
   IF(NOT APPLE)
-    SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
+    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-Bsymbolic")
   ELSE(NOT APPLE)
-    SET( CMAKE_SHARED_LINKER_FLAGS "-Wl -undefined dynamic_lookup")
+    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl -undefined dynamic_lookup")
   ENDIF(NOT APPLE) 
 ENDIF(MSVC)
 
