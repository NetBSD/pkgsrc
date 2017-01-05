$NetBSD: patch-Modules_FindCurses.cmake,v 1.1 2017/01/05 22:34:25 joerg Exp $

--- Modules/FindCurses.cmake.orig	2017-01-05 22:24:12.384738412 +0000
+++ Modules/FindCurses.cmake
@@ -167,8 +167,8 @@ if(NOT DEFINED CURSES_HAVE_CURSES_H)
   endif()
 endif()
 
-find_library(CURSES_FORM_LIBRARY form HINTS "${_cursesLibDir}")
-find_library(CURSES_FORM_LIBRARY form )
+find_library(CURSES_FORM_LIBRARY form gnuform HINTS "${_cursesLibDir}")
+find_library(CURSES_FORM_LIBRARY form gnuform)
 
 # Previous versions of FindCurses provided these values.
 if(NOT DEFINED FORM_LIBRARY)
