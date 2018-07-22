$NetBSD: patch-cmake_FindNcurses.cmake,v 1.1 2018/07/22 21:32:34 maya Exp $

Try the following order:
ncursesw, then plain curses, then ncurses.
NCURSES_LIBRARY must be defined.
(for netbsd curses)

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
@@ -33,6 +33,16 @@ find_library(NCURSESW_LIBRARY
   PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
 )
 
+find_library(NCURSES_LIBRARY
+  NAMES ncurses
+  PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
+)
+
+find_library(CURSES_LIBRARY
+  NAMES curses
+  PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
+)
+
 if(NCURSESW_LIBRARY)
   find_package(PkgConfig QUIET)
   if(PKG_CONFIG_FOUND)
@@ -40,21 +50,21 @@ if(NCURSESW_LIBRARY)
     set(NCURSESW_LIBRARY ${NCURSES_LIBRARIES} ${NCURSES_CFLAGS_OTHER})
   endif()
   set(NCURSES_LIBRARY ${NCURSESW_LIBRARY})
-else()
-  find_library(NCURSES_LIBRARY
-    NAMES ncurses
-    PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
-  )
+
+
+elseif(CURSES_LIBRARY)
+  set(NCURSES_LIBRARY ${CURSES_LIBRARY})
+
+
+elseif(NCURSES_LIBRARY)
   find_package(PkgConfig QUIET)
   if(PKG_CONFIG_FOUND)
     pkg_search_module(NCURSES ncurses)
     set(NCURSES_LIBRARY ${NCURSES_LIBRARIES} ${NCURSES_CFLAGS_OTHER})
   endif()
-  if(NCURSES_LIBRARY)
-    message("*** WARNING:\n"
-      "*** ncursesw library not found! Falling back to \"ncurses\"\n"
-      "*** Be careful, UTF-8 display may not work properly if your locale is UTF-8.")
-  endif()
+  message("*** WARNING:\n"
+    "*** ncursesw library not found! Falling back to \"ncurses\"\n"
+    "*** Be careful, UTF-8 display may not work properly if your locale is UTF-8.")
 endif()
 
 if(NCURSES_INCLUDE_PATH AND NCURSES_LIBRARY)
