$NetBSD: patch-cmake_ConfigureChecks.cmake,v 1.1 2025/12/13 17:58:55 vins Exp $

On some systems, libterminfo has a longer name.
https://github.com/fish-shell/fish-shell/pull/9794

--- cmake/ConfigureChecks.cmake.orig	2024-01-01 15:15:17.000000000 +0000
+++ cmake/ConfigureChecks.cmake
@@ -86,6 +86,11 @@ else()
         set(CURSES_LIBRARY ${CURSES_LIBRARY} ${CURSES_TINFO})
     endif()
 endif()
+# on some systems, libterminfo has a longer name
+find_library(CURSES_TINFO terminfo)
+if (CURSES_TINFO)
+    set(CURSES_LIBRARY ${CURSES_LIBRARY} ${CURSES_TINFO})
+endif()
 
 # Get threads.
 set(THREADS_PREFER_PTHREAD_FLAG ON)
