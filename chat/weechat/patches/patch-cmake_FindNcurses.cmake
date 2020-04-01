$NetBSD: patch-cmake_FindNcurses.cmake,v 1.6 2020/04/01 14:58:50 nia Exp $

Find NetBSD libcurses.

--- cmake/FindNcurses.cmake.orig	2020-03-29 07:39:36.000000000 +0000
+++ cmake/FindNcurses.cmake
@@ -41,7 +41,7 @@ if(NCURSESW_LIBRARY)
   set(NCURSES_LIBRARY ${NCURSESW_LIBRARY})
 else()
   find_library(NCURSES_LIBRARY
-    NAMES ncurses
+    NAMES curses ncurses
     PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
   )
   find_package(PkgConfig QUIET)
