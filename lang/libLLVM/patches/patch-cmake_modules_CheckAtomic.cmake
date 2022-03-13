$NetBSD: patch-cmake_modules_CheckAtomic.cmake,v 1.2 2022/03/13 15:22:32 tnn Exp $

Omit check for native 8-byte atomics, platform may not have them,
and they are actually not required here.  Makes powerpc build llvm.

--- cmake/modules/CheckAtomic.cmake.orig	2021-06-28 16:23:38.000000000 +0000
+++ cmake/modules/CheckAtomic.cmake
@@ -66,20 +66,21 @@ if(MSVC)
   set(HAVE_CXX_ATOMICS64_WITHOUT_LIB True)
 elseif(LLVM_COMPILER_IS_GCC_COMPATIBLE)
   # First check if atomics work without the library.
-  check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITHOUT_LIB)
-  # If not, check if the library exists, and atomics work with it.
-  if(NOT HAVE_CXX_ATOMICS64_WITHOUT_LIB)
-    check_library_exists(atomic __atomic_load_8 "" HAVE_CXX_LIBATOMICS64)
-    if(HAVE_CXX_LIBATOMICS64)
-      list(APPEND CMAKE_REQUIRED_LIBRARIES "atomic")
-      check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITH_LIB)
-      if (NOT HAVE_CXX_ATOMICS64_WITH_LIB)
-        message(FATAL_ERROR "Host compiler must support 64-bit std::atomic!")
-      endif()
-    else()
-      message(FATAL_ERROR "Host compiler appears to require libatomic for 64-bit operations, but cannot find it.")
-    endif()
-  endif()
+  set(HAVE_CXX_ATOMICS64_WITHOUT_LIB True)
+#  check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITHOUT_LIB)
+#  # If not, check if the library exists, and atomics work with it.
+#  if(NOT HAVE_CXX_ATOMICS64_WITHOUT_LIB)
+#    check_library_exists(atomic __atomic_load_8 "" HAVE_CXX_LIBATOMICS64)
+#    if(HAVE_CXX_LIBATOMICS64)
+#      list(APPEND CMAKE_REQUIRED_LIBRARIES "atomic")
+#      check_working_cxx_atomics64(HAVE_CXX_ATOMICS64_WITH_LIB)
+#      if (NOT HAVE_CXX_ATOMICS64_WITH_LIB)
+#        message(FATAL_ERROR "Host compiler must support 64-bit std::atomic!")
+#      endif()
+#    else()
+#      message(FATAL_ERROR "Host compiler appears to require libatomic for 64-bit operations, but cannot find it.")
+#    endif()
+#  endif()
 endif()
 
 ## TODO: This define is only used for the legacy atomic operations in
