$NetBSD: patch-filesystem_filesystem.hpp,v 1.3 2022/05/23 13:08:02 micha Exp $

Disable use of experimental compiler features.
Failed with GCC 7.4.0 on NetBSD.

--- filesystem/filesystem.hpp.orig	2021-05-24 09:14:03.505674000 +0000
+++ filesystem/filesystem.hpp
@@ -72,6 +72,7 @@
 #define GHC_OS_CYGWIN
 #elif defined(__svr4__)
 #define GHC_OS_SYS5R4
+#define GHC_NO_DIRENT_D_TYPE
 #elif defined(BSD)
 #define GHC_OS_BSD
 #elif defined(__EMSCRIPTEN__)
@@ -241,6 +242,7 @@
 #define GHC_HAS_STD_STRING_VIEW
 #endif
 
+#if 0 // pkgsrc
 // Standard library support for std::experimental::string_view.
 #if defined(_LIBCPP_VERSION) && (_LIBCPP_VERSION >= 3700 && _LIBCPP_VERSION < 7000) && (__cplusplus >= 201402)
 #define GHC_HAS_STD_EXPERIMENTAL_STRING_VIEW
@@ -250,6 +252,7 @@
 // macro _GLIBCXX_USE_DUAL_ABI is always defined in libstdc++ from gcc-5 and newer
 #define GHC_HAS_STD_EXPERIMENTAL_STRING_VIEW
 #endif
+#endif
 
 #if defined(GHC_HAS_STD_STRING_VIEW)
 #include <string_view>
