$NetBSD: patch-CMakeModules_KiCadFullVersion.cmake,v 1.2 2022/01/02 19:10:03 tnn Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and contains multiple directories

--- CMakeModules/KiCadFullVersion.cmake.orig	2021-12-22 13:32:19.000000000 +0000
+++ CMakeModules/KiCadFullVersion.cmake
@@ -28,7 +28,7 @@
 # KICAD_VERSION_EXTRA is then appended to the base version string.
 
 # Use git to determine the version string if it's available.
-include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+include( ${SRC_PATH}/CMakeModules/CreateGitVersionHeader.cmake )
 create_git_version_header( ${SRC_PATH} )
 
 # $KICAD_VERSION is set in KiCadVersion.cmake or by git (if it is available).
