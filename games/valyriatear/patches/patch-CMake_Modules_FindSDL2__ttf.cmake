$NetBSD: patch-CMake_Modules_FindSDL2__ttf.cmake,v 1.1 2026/03/10 09:09:53 adam Exp $

Fix for newer CMake.

--- CMake/Modules/FindSDL2_ttf.cmake.orig	2026-03-10 08:35:02.820680595 +0000
+++ CMake/Modules/FindSDL2_ttf.cmake
@@ -74,7 +74,7 @@ endif()
 set(SDL2_TTF_LIBRARIES ${SDL2_TTF_LIBRARY})
 set(SDL2_TTF_INCLUDE_DIRS ${SDL2_TTF_INCLUDE_DIR})
 
-# include(${CMAKE_CURRENT_LIST_DIR}/FindPackageHandleStandardArgs.cmake)
+include(FindPackageHandleStandardArgs)
 
 FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_ttf
                                   REQUIRED_VARS SDL2_TTF_LIBRARIES SDL2_TTF_INCLUDE_DIRS
