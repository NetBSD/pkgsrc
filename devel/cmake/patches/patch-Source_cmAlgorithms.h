$NetBSD: patch-Source_cmAlgorithms.h,v 1.2 2019/03/18 09:05:59 adam Exp $

Handle mismatch between C++ compiler and C++ library by checking for C++17 features
(std::size, std::cend, std::cbegin)
https://gitlab.kitware.com/cmake/cmake/merge_requests/3030/diffs

--- Source/cmAlgorithms.h.orig	2019-03-14 13:15:54.000000000 +0000
+++ Source/cmAlgorithms.h
@@ -375,7 +375,8 @@ std::unique_ptr<T> make_unique(Args&&...
 
 #endif
 
-#if __cplusplus >= 201703L || defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
+#if defined(CMake_HAVE_CXX_SIZE_T) ||                                         \
+  defined(_MSVC_LANG) && _MSVC_LANG >= 201703L
 
 using std::size;
 
@@ -410,14 +411,14 @@ int isize(const T& t)
   return static_cast<int>(cm::size(t));
 }
 
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
@@ -429,6 +430,16 @@ constexpr auto cbegin(C const& c) noexce
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
