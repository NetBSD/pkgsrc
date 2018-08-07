$NetBSD: patch-cmake_config-ix.cmake,v 1.3 2018/08/07 10:44:50 adam Exp $

Do not generate invalid llvm-config in pkgsrc.

--- cmake/config-ix.cmake.orig	2018-01-02 17:53:08.000000000 +0000
+++ cmake/config-ix.cmake
@@ -153,7 +153,7 @@ if(NOT LLVM_USE_SANITIZER MATCHES "Memor
     endif()
     if(LLVM_ENABLE_TERMINFO)
       set(HAVE_TERMINFO 0)
-      foreach(library tinfo terminfo curses ncurses ncursesw)
+      foreach(library terminfo curses ncurses ncursesw tinfo)
         string(TOUPPER ${library} library_suffix)
         check_library_exists(${library} setupterm "" HAVE_TERMINFO_${library_suffix})
         if(HAVE_TERMINFO_${library_suffix})
