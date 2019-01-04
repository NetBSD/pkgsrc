$NetBSD: patch-Modules_FindCurses.cmake,v 1.2 2019/01/04 17:47:12 triaxx Exp $

Recognize libgnuform as valid implementation of a form library to match
devel/ncurses. This is necessary due to cmake's insistance of scanning
PREFIX/lib directly.

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
