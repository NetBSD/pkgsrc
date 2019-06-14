$NetBSD: patch-CMakeModules_WriteVersionHeader.cmake,v 1.4 2019/06/14 15:59:32 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/WriteVersionHeader.cmake.orig	2018-07-13 19:53:52.000000000 +0000
+++ CMakeModules/WriteVersionHeader.cmake
@@ -26,11 +26,11 @@
 # not defined during the build configuration.  If CreateGitVersionHeader
 # cannot determine the current repo version, a version.h file is still
 # created with KICAD_VERSION set in KiCadVersion.cmake.
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/KiCadVersion.cmake )
 
 # Always use git if it's available to determine the version string.
 message( STATUS "Using Git to determine build version string." )
-include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/CreateGitVersionHeader.cmake )
 create_git_version_header( ${SRC_PATH} )
 
 # $KICAD_VERSION will always be set to something.  Even if it is the default
