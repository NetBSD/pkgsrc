$NetBSD: patch-cmake_modules_CheckAtomic.cmake,v 1.2 2020/04/18 07:50:18 adam Exp $

Omit check for native 8-byte atomics, platform may not have them,
and they are actually not required here.  Makes powerpc build llvm.

--- cmake/modules/CheckAtomic.cmake.orig	2020-03-19 09:19:04.000000000 +0000
+++ cmake/modules/CheckAtomic.cmake
@@ -62,19 +62,6 @@ else()
   check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITHOUT_LIB)
 endif()
 
-# If not, check if the library exists, and atomics work with it.
-if(NOT HAVE_CXX_ATOMICS64_WITHOUT_LIB)
-  check_library_exists(atomic __atomic_load_8 "" HAVE_CXX_LIBATOMICS64)
-  if(HAVE_CXX_LIBATOMICS64)
-    list(APPEND CMAKE_REQUIRED_LIBRARIES "atomic")
-    check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITH_LIB)
-    if (NOT HAVE_CXX_ATOMICS64_WITH_LIB)
-      message(FATAL_ERROR "Host compiler must support 64-bit std::atomic!")
-    endif()
-  else()
-    message(FATAL_ERROR "Host compiler appears to require libatomic for 64-bit operations, but cannot find it.")
-  endif()
-endif()
 
 ## TODO: This define is only used for the legacy atomic operations in
 ## llvm's Atomic.h, which should be replaced.  Other code simply
