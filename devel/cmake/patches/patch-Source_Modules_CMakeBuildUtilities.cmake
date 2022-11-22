$NetBSD: patch-Source_Modules_CMakeBuildUtilities.cmake,v 1.1 2022/11/22 19:14:03 adam Exp $

Don't insist on ncurses.

--- Source/Modules/CMakeBuildUtilities.cmake.orig	2022-11-22 18:51:08.946372477 +0000
+++ Source/Modules/CMakeBuildUtilities.cmake
@@ -352,7 +352,6 @@ if(NOT DEFINED BUILD_CursesDialog)
 endif()
 if(BUILD_CursesDialog)
   if(UNIX)
-    set(CURSES_NEED_NCURSES TRUE)
     find_package(Curses)
     if(NOT CURSES_FOUND)
       message(WARNING
