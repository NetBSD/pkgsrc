$NetBSD: patch-CMakeModules_WriteVersionHeader.cmake,v 1.3 2018/03/01 13:59:11 mef Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/WriteVersionHeader.cmake.orig	2017-03-06 23:58:56.000000000 +0000
+++ CMakeModules/WriteVersionHeader.cmake
@@ -26,14 +26,14 @@
 # not defined during the build configuration.  If
 # CreateGitVersionHeader cannot determine the current repo version, a
 # version.h file is still created with KICAD_VERSION set to "no-vcs-found".
-include( ${CMAKE_MODULE_PATH}/KiCadVersion.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/KiCadVersion.cmake )
 
 # Attempt to detect if we have a git repo and set the version string if
 # the version wasn't set to something other than the default value in
 # KiCadVersion.cmake.
 if( KICAD_VERSION STREQUAL "no-vcs-found" AND EXISTS "${SRC_PATH}/.git" )
     message( STATUS "Using Git to determine build version string." )
-    include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+    include( ${PROJECT_SOURCE_DIR}/CMakeModules/CreateGitVersionHeader.cmake )
     create_git_version_header( ${SRC_PATH} )
 endif()
 
