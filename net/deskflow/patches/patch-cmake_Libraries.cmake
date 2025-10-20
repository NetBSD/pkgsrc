$NetBSD: patch-cmake_Libraries.cmake,v 1.1 2025/10/20 19:49:12 tnn Exp $

- package should not try to mess manually with --sysroot

--- cmake/Libraries.cmake.orig	2025-10-16 11:40:33.871755971 +0000
+++ cmake/Libraries.cmake
@@ -137,7 +137,7 @@ macro(configure_unix_libs)
   endif()
 
   if(APPLE)
-    set(CMAKE_CXX_FLAGS "--sysroot ${CMAKE_OSX_SYSROOT} ${CMAKE_CXX_FLAGS} -DGTEST_USE_OWN_TR1_TUPLE=1")
+    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_USE_OWN_TR1_TUPLE=1")
     find_library(lib_ScreenSaver ScreenSaver)
     find_library(lib_IOKit IOKit)
     find_library(lib_ApplicationServices ApplicationServices)
