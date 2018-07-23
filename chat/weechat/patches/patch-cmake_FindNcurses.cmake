$NetBSD: patch-cmake_FindNcurses.cmake,v 1.2 2018/07/23 22:57:22 maya Exp $

Don't try to look for ncurses.h, so FAKE_NCURSES works for netbsd curses.

--- cmake/FindNcurses.cmake.orig	2018-03-18 06:41:40.000000000 +0000
+++ cmake/FindNcurses.cmake
@@ -22,7 +22,7 @@ if(NCURSES_FOUND)
 endif()
 
 find_path(NCURSES_INCLUDE_PATH
-  NAMES ncurses.h curses.h
+  NAMES curses.h
   PATHS /usr/include/ncursesw /usr/include/ncurses /usr/include
   /usr/local/include/ncursesw /usr/local/include/ncurses /usr/local/include
   /usr/pkg/include/ncursesw /usr/pkg/include/ncurses /usr/pkg/include
