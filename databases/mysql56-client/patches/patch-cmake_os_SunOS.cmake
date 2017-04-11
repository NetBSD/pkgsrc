$NetBSD: patch-cmake_os_SunOS.cmake,v 1.2 2017/04/11 20:21:02 adam Exp $

Backport section from MySQL 5.7 to fix SunOS/gcc.

--- cmake/os/SunOS.cmake.orig	2017-03-18 06:43:12.000000000 +0000
+++ cmake/os/SunOS.cmake
@@ -19,7 +19,13 @@ INCLUDE(CheckCSourceCompiles) 
 
 # We require SunStudio 12u2 (CC 5.11)
 IF(NOT FORCE_UNSUPPORTED_COMPILER)
-  IF(CMAKE_C_COMPILER_ID MATCHES "SunPro")
+  IF(CMAKE_COMPILER_IS_GNUCC)
+    EXECUTE_PROCESS(COMMAND ${CMAKE_C_COMPILER} -dumpversion
+                    OUTPUT_VARIABLE GCC_VERSION)
+    IF(GCC_VERSION VERSION_LESS 4.4)
+      MESSAGE(FATAL_ERROR "GCC 4.4 or newer is required!")
+    ENDIF()
+  ELSEIF(CMAKE_C_COMPILER_ID MATCHES "SunPro")
     # CC -V yields
     # CC: Studio 12.6 Sun C++ 5.15 SunOS_sparc Beta 2016/12/19
     # CC: Studio 12.5 Sun C++ 5.14 SunOS_sparc Dodona 2016/04/04
