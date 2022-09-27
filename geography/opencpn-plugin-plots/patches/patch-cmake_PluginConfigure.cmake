$NetBSD: patch-cmake_PluginConfigure.cmake,v 1.1 2022/09/27 10:04:39 bouyer Exp $
Do not overwrite CMAKE_SHARED_LINKER_FLAGS

--- cmake/PluginConfigure.cmake.orig	2022-09-27 11:57:14.210931921 +0200
+++ cmake/PluginConfigure.cmake	2022-09-27 11:57:29.413310899 +0200
@@ -228,9 +228,6 @@
 
 include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
 
-set(CMAKE_SHARED_LINKER_FLAGS "")
-set(CMAKE_EXE_LINKER_FLAGS "")
-
 # SET(PROFILING 1)
 if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
     add_definitions("-DDEBUG_BUILD")
