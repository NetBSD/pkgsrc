$NetBSD: patch-cmake_config-ix.cmake,v 1.7 2022/08/12 08:37:58 pin Exp $

Do not generate invalid llvm-config in pkgsrc.
Allow override of pthread library selection via PKGSRC_LLVM_PTHREADLIB.

--- cmake/config-ix.cmake.orig	2022-06-22 16:46:24.000000000 +0000
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
