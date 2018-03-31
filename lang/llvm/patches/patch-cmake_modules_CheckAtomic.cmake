$NetBSD: patch-cmake_modules_CheckAtomic.cmake,v 1.1 2018/03/31 15:13:28 he Exp $

Omit check for native 8-byte atomics, platform may not have them,
and they are actually not required here.  Makes powerpc build llvm.

--- cmake/modules/CheckAtomic.cmake.orig	2016-06-23 06:39:35.000000000 +0000
+++ cmake/modules/CheckAtomic.cmake
@@ -62,18 +62,18 @@ else()
 endif()
 
 # If not, check if the library exists, and atomics work with it.
-if(NOT HAVE_CXX_ATOMICS64_WITHOUT_LIB)
-  check_library_exists(atomic __atomic_load_8 "" HAVE_CXX_LIBATOMICS64)
-  if(HAVE_CXX_LIBATOMICS64)
-    list(APPEND CMAKE_REQUIRED_LIBRARIES "atomic")
-    check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITH_LIB)
-    if (NOT HAVE_CXX_ATOMICS64_WITH_LIB)
-      message(FATAL_ERROR "Host compiler must support std::atomic!")
-    endif()
-  else()
-    message(FATAL_ERROR "Host compiler appears to require libatomic, but cannot find it.")
-  endif()
-endif()
+#if(NOT HAVE_CXX_ATOMICS64_WITHOUT_LIB)
+#  check_library_exists(atomic __atomic_load_8 "" HAVE_CXX_LIBATOMICS64)
+#  if(HAVE_CXX_LIBATOMICS64)
+#    list(APPEND CMAKE_REQUIRED_LIBRARIES "atomic")
+#    check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITH_LIB)
+#    if (NOT HAVE_CXX_ATOMICS64_WITH_LIB)
+#      message(FATAL_ERROR "Host compiler must support std::atomic!")
+#    endif()
+#  else()
+#    message(FATAL_ERROR "Host compiler appears to require libatomic, but cannot find it.")
+#  endif()
+#endif()
 
 ## TODO: This define is only used for the legacy atomic operations in
 ## llvm's Atomic.h, which should be replaced.  Other code simply
