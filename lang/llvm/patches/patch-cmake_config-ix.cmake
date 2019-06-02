$NetBSD: patch-cmake_config-ix.cmake,v 1.4 2019/06/02 08:35:55 adam Exp $

Do not generate invalid llvm-config in pkgsrc.

--- cmake/config-ix.cmake.orig	2018-11-26 00:03:39.000000000 +0000
+++ cmake/config-ix.cmake
@@ -129,7 +129,7 @@ if(NOT LLVM_USE_SANITIZER MATCHES "Memor
     endif()
     if(LLVM_ENABLE_TERMINFO)
       set(HAVE_TERMINFO 0)
-      foreach(library terminfo tinfo curses ncurses ncursesw)
+      foreach(library terminfo curses ncurses ncursesw tinfo)
         string(TOUPPER ${library} library_suffix)
         check_library_exists(${library} setupterm "" HAVE_TERMINFO_${library_suffix})
         if(HAVE_TERMINFO_${library_suffix})
