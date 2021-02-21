$NetBSD: patch-CMakeModules_KiCadFullVersion.cmake,v 1.1 2021/02/21 18:56:36 bouyer Exp $

Don't use ${CMAKE_MODULE_PATH} directly as it will be changed
and containt multiple directories

--- CMakeModules/KiCadFullVersion.cmake.orig	2021-02-20 11:23:32.177620736 +0100
+++ CMakeModules/KiCadFullVersion.cmake	2021-02-20 11:23:47.641157793 +0100
@@ -28,7 +28,7 @@
 # KICAD_VERSION_EXTRA is then appended to the base version string.
 
 # Use git to determine the version string if it's available.
-include( ${CMAKE_MODULE_PATH}/CreateGitVersionHeader.cmake )
+include( ${CMAKE_CURRENT_LIST_DIR}/CreateGitVersionHeader.cmake )
 create_git_version_header( ${SRC_PATH} )
 
 # $KICAD_VERSION is set in KiCadVersion.cmake or by git (if it is available).
