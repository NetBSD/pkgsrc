$NetBSD: patch-cmake_ConfigureChecks.cmake,v 1.4 2023/05/16 17:04:56 wiz Exp $

On some systems, libterminfo has a longer name.
https://github.com/fish-shell/fish-shell/pull/9794

--- cmake/ConfigureChecks.cmake.orig	2023-03-25 06:50:41.000000000 +0000
+++ cmake/ConfigureChecks.cmake
@@ -80,6 +80,11 @@ find_library(CURSES_TINFO tinfo)
 if (CURSES_TINFO)
     set(CURSES_LIBRARY ${CURSES_LIBRARY} ${CURSES_TINFO})
 endif()
+# on some systems, libterminfo has a longer name
+find_library(CURSES_TINFO terminfo)
+if (CURSES_TINFO)
+    set(CURSES_LIBRARY ${CURSES_LIBRARY} ${CURSES_TINFO})
+endif()
 
 # Get threads.
 set(THREADS_PREFER_PTHREAD_FLAG ON)
