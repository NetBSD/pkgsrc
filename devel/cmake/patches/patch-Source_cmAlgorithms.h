$NetBSD: patch-Source_cmAlgorithms.h,v 1.1 2019/02/27 13:18:01 maya Exp $

Handle mismatch between C++ compiler and C++ library by checking for C++17 features
(std::size, std::cend, std::cbegin)
https://gitlab.kitware.com/cmake/cmake/merge_requests/3030/diffs

--- Source/cmAlgorithms.h.orig	2019-02-01 13:35:27.000000000 +0000
+++ Source/cmAlgorithms.h
@@ -367,7 +367,8 @@ std::unique_ptr<T> make_unique(Args&&...
 
 #endif
 
-#if __cplusplus >= 201703L || defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
+#if defined(CMake_HAVE_CXX_SIZE_T) ||                                         \
+  defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
 
 using std::size;
 
@@ -396,14 +397,14 @@ constexpr
 
 #endif
 
-#if __cplusplus >= 201402L || defined(_MSVC_LANG) && _MSVC_LANG >= 201402L
+#if defined(CMake_HAVE_CXX_CBEGIN) ||                                         \
+  defined(_MSVC_LANG) && _MSVC_LANG >= 201402L
 
 using std::cbegin;
-using std::cend;
 
 #else
 
-// std::c{begin,end} backport from C++14
+// std::cbegin backport from C++14
 template <class C>
 #  if defined(_MSC_VER) && _MSC_VER < 1900
 auto cbegin(C const& c)
@@ -415,6 +416,16 @@ constexpr auto cbegin(C const& c) noexce
   return std::begin(c);
 }
 
+#endif
+
+#if defined(CMake_HAVE_CXX_CEND) ||                                           \
+  defined(_MSVC_LANG) && _MSVC_LANG >= 201402L
+
+using std::cend;
+
+#else
+
+// std::cend backport from C++14
 template <class C>
 #  if defined(_MSC_VER) && _MSC_VER < 1900
 auto cend(C const& c)
