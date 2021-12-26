$NetBSD: patch-cmake_config-ix.cmake,v 1.6 2021/12/26 21:52:11 he Exp $

Do not generate invalid llvm-config in pkgsrc.
Allow override of pthread library selection via PKGSRC_LLVM_PTHREADLIB.

--- cmake/config-ix.cmake.orig	2021-04-06 16:38:18.000000000 +0000
+++ cmake/config-ix.cmake
@@ -113,7 +113,11 @@ if(HAVE_LIBPTHREAD)
   set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
   set(THREADS_HAVE_PTHREAD_ARG Off)
   find_package(Threads REQUIRED)
-  set(LLVM_PTHREAD_LIB ${CMAKE_THREAD_LIBS_INIT})
+  if(PKGSRC_LLVM_PTHREADLIB)
+    set(LLVM_PTHREAD_LIB ${PKGSRC_LLVM_PTHREADLIB})
+  else()
+    set(LLVM_PTHREAD_LIB ${CMAKE_THREAD_LIBS_INIT})
+  endif()
 endif()
 
 if(LLVM_ENABLE_ZLIB)
@@ -176,7 +180,7 @@ if(NOT LLVM_USE_SANITIZER MATCHES "Memor
       set(MAYBE_REQUIRED)
     endif()
     if(LLVM_ENABLE_TERMINFO)
-      find_library(TERMINFO_LIB NAMES terminfo tinfo curses ncurses ncursesw ${MAYBE_REQUIRED})
+      find_library(TERMINFO_LIB NAMES terminfo curses ncurses ncursesw tinfo ${MAYBE_REQUIRED})
     endif()
     if(TERMINFO_LIB)
       set(LLVM_ENABLE_TERMINFO 1)
