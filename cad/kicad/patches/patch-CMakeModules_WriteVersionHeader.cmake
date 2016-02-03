$NetBSD: patch-CMakeModules_WriteVersionHeader.cmake,v 1.1 2016/02/03 19:34:33 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/WriteVersionHeader.cmake.orig	2015-12-14 20:13:21.000000000 +0100
+++ CMakeModules/WriteVersionHeader.cmake	2015-12-14 20:14:58.000000000 +0100
@@ -32,12 +32,12 @@
     # Detect the appropiate VCS and set the version string.
     if( EXISTS "${SRC_PATH}/.bzr" )
         message( STATUS "Using Bazaar to determine build version string." )
-        include( ${CMAKE_MODULE_PATH}/CreateBzrVersionHeader.cmake )
+        include( ${PROJECT_SOURCE_DIR}/CMakeModules/CreateBzrVersionHeader.cmake )
         create_bzr_version_header( ${SRC_PATH} )
         set( _wvh_version_str ${KICAD_BUILD_VERSION} )
     elseif( EXISTS "${SRC_PATH}/.git" )
         message( STATUS "Using Git to determine build version string." )
-        include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+        include( ${PROJECT_SOURCE_DIR}/CMakeModules/CreateGitVersionHeader.cmake )
         create_git_version_header( ${SRC_PATH} )
         set( _wvh_version_str ${KICAD_BUILD_VERSION} )
     endif()
