$NetBSD: patch-CMakeModules_BuildSteps_WritePlatformMetadata__linux.cmake,v 1.1 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/BuildSteps/WritePlatformMetadata_linux.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/BuildSteps/WritePlatformMetadata_linux.cmake
@@ -32,8 +32,8 @@
 message( STATUS "Creating linux metadata" )
 
 # Create the KiCad version strings
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
-include( ${CMAKE_MODULE_PATH}/KiCadFullVersion.cmake )
+include( ${SRC_PATH}/CMakeModules/KiCadVersion.cmake )
+include( ${SRC_PATH}/CMakeModules/KiCadFullVersion.cmake )
 
 # Create the date of the configure
 string( TIMESTAMP KICAD_CONFIG_TIMESTAMP "%Y-%m-%d" )
