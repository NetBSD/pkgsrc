$NetBSD: patch-CMakeModules_WritePlatformMetadata__macos.cmake,v 1.1 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/WritePlatformMetadata_macos.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/WritePlatformMetadata_macos.cmake
@@ -29,8 +29,8 @@ message( STATUS "Creating MacOS metadata
 
 # Create the KiCad version strings
 set( SRC_PATH ${PROJECT_SOURCE_DIR} )
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
-include( ${CMAKE_MODULE_PATH}/KiCadFullVersion.cmake )
+include( ${PROJECT_SOURCE_DIR}/CMakeModules/KiCadVersion.cmake )
+include( ${PROJECT_SOURCE_DIR}/CMakeModules/KiCadFullVersion.cmake )
 
 
 # Configure each plist file from the respurces directory and store it in the build directory
