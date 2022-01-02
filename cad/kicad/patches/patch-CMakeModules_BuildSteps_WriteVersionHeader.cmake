$NetBSD: patch-CMakeModules_BuildSteps_WriteVersionHeader.cmake,v 1.1 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/BuildSteps/WriteVersionHeader.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/BuildSteps/WriteVersionHeader.cmake
@@ -23,8 +23,8 @@
 #
 
 # Create the KiCad version strings
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
-include( ${CMAKE_MODULE_PATH}/KiCadFullVersion.cmake )
+include( ${SRC_PATH}/CMakeModules/KiCadVersion.cmake )
+include( ${SRC_PATH}/CMakeModules/KiCadFullVersion.cmake )
 
 # Extract the major and minor build version as a string
 string( REGEX MATCH
