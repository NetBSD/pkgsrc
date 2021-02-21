$NetBSD: patch-CMakeModules_WritePlatformMetadata_linux.cmake,v 1.1 2021/02/21 18:56:36 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/WritePlatformMetadata_linux.cmake.orig	2021-02-20 11:19:52.763869474 +0100
+++ CMakeModules/WritePlatformMetadata_linux.cmake	2021-02-20 11:20:17.630383892 +0100
@@ -29,8 +29,8 @@
 
 # Create the KiCad version strings
 set( SRC_PATH ${PROJECT_SOURCE_DIR} )
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
-include( ${CMAKE_MODULE_PATH}/KiCadFullVersion.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/KiCadVersion.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/KiCadFullVersion.cmake )
 
 # Create the date of the configure
 string( TIMESTAMP KICAD_CONFIG_TIMESTAMP "%Y-%m-%d" )
