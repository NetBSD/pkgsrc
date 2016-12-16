$NetBSD: patch-cmake_os_SunOS.cmake,v 1.1 2016/12/16 17:55:48 jperkin Exp $

Backport section from MySQL 5.7 to fix SunOS/gcc.

--- cmake/os/SunOS.cmake.orig	2016-11-28 13:36:22.000000000 +0000
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
     # CC: Studio 12.5 Sun C++ 5.14 SunOS_sparc Dodona 2016/04/04
     # CC: Sun C++ 5.13 SunOS_sparc Beta 2014/03/11
