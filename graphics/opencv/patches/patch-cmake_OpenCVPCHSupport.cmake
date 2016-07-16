$NetBSD: patch-cmake_OpenCVPCHSupport.cmake,v 1.1 2016/07/16 03:49:57 markd Exp $

gcc6 trips up ".../cstdlib:75:25: fatal error: stdlib.h: No such file or directory" because of -isystem

--- cmake/OpenCVPCHSupport.cmake.orig	2015-12-18 15:02:16.000000000 +0000
+++ cmake/OpenCVPCHSupport.cmake
@@ -19,7 +19,7 @@ IF(CMAKE_COMPILER_IS_GNUCXX)
         ARGS ${CMAKE_CXX_COMPILER_ARG1} -dumpversion
         OUTPUT_VARIABLE gcc_compiler_version)
     #MESSAGE("GCC Version: ${gcc_compiler_version}")
-    IF(gcc_compiler_version VERSION_GREATER "4.2.-1")
+    IF(gcc_compiler_version VERSION_GREATER "4.2.-1" AND gcc_compiler_version VERSION_LESS "6.0.0")
         SET(PCHSupport_FOUND TRUE)
     ENDIF()
 
