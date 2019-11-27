$NetBSD: patch-Modules_FindCurses.cmake,v 1.3 2019/11/27 22:32:27 adam Exp $

Recognize libgnuform as valid implementation of a form library to match
devel/ncurses. This is necessary due to cmake's insistance of scanning
PREFIX/lib directly.

--- Modules/FindCurses.cmake.orig	2019-11-26 14:18:07.000000000 +0000
+++ Modules/FindCurses.cmake
@@ -225,8 +225,8 @@ if(NOT CURSES_NEED_WIDE)
   endif()
 endif()
 
-find_library(CURSES_FORM_LIBRARY "${CURSES_FORM_LIBRARY_NAME}" HINTS "${_cursesLibDir}")
-find_library(CURSES_FORM_LIBRARY "${CURSES_FORM_LIBRARY_NAME}" )
+find_library(CURSES_FORM_LIBRARY "${CURSES_FORM_LIBRARY_NAME}" gnuform HINTS "${_cursesLibDir}")
+find_library(CURSES_FORM_LIBRARY "${CURSES_FORM_LIBRARY_NAME}" gnuform)
 
 # Previous versions of FindCurses provided these values.
 if(NOT DEFINED FORM_LIBRARY)
