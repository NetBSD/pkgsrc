$NetBSD: patch-cmake_FindNcurses.cmake,v 1.3 2019/03/23 14:54:13 nia Exp $

Don't try to look for ncurses.h, so FAKE_NCURSES works for netbsd curses.

--- cmake/FindNcurses.cmake.orig	2019-02-17 07:20:07.000000000 +0000
+++ cmake/FindNcurses.cmake
@@ -22,7 +22,7 @@ if(NCURSES_FOUND)
 endif()
 
 find_path(NCURSES_INCLUDE_PATH
-  NAMES ncurses.h curses.h
+  NAMES curses.h
   PATHS /usr/include/ncursesw /usr/include/ncurses /usr/include
   /usr/local/include/ncursesw /usr/local/include/ncurses /usr/local/include
   /usr/pkg/include/ncursesw /usr/pkg/include/ncurses /usr/pkg/include
@@ -42,7 +42,7 @@ if(NCURSESW_LIBRARY)
   set(NCURSES_LIBRARY ${NCURSESW_LIBRARY})
 else()
   find_library(NCURSES_LIBRARY
-    NAMES ncurses
+    NAMES curses ncurses
     PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
   )
   find_package(PkgConfig QUIET)
