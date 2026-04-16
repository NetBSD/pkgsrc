$NetBSD: patch-cmake_modules_FindCursesAndPanel.cmake,v 1.1 2026/04/16 06:33:50 wiz Exp $

On NetBSD, the library is called libterminfo.
https://github.com/llvm/llvm-project/issues/191532

--- cmake/modules/FindCursesAndPanel.cmake.orig	2025-12-12 10:35:47.000000000 +0000
+++ cmake/modules/FindCursesAndPanel.cmake
@@ -40,7 +40,7 @@ else()
                             CURSES_HAS_TINFO)
     if(NOT CURSES_HAS_TINFO)
       message(STATUS "curses library missing terminfo symbols, looking for tinfo separately")
-      find_library(TINFO_LIBRARIES NAMES tinfo DOC "The curses tinfo library" QUIET)
+      find_library(TINFO_LIBRARIES NAMES tinfo terminfo DOC "The curses tinfo library" QUIET)
       list(APPEND CURSES_LIBRARIES "${TINFO_LIBRARIES}")
     endif()
     set(HAS_TERMINFO_SYMBOLS "$<OR:$<BOOL:${TERMINFO_LIBRARIES}>,$<BOOL:${CURSES_HAS_TINFO}>>")
