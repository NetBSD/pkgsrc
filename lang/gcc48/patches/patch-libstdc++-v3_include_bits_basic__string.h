$NetBSD: patch-libstdc++-v3_include_bits_basic__string.h,v 1.1 2017/05/28 01:00:20 maya Exp $

Backport of r223830
Don't hide all of to_string if _GLIBCXX_HAVE_BROKEN_VSWPRINTF
only to_wstring (Applies to NetBSD-6-0)

--- libstdc++-v3/include/bits/basic_string.h.orig	2013-05-15 22:00:48.000000000 +0000
+++ libstdc++-v3/include/bits/basic_string.h
@@ -2809,8 +2809,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
 _GLIBCXX_END_NAMESPACE_VERSION
 } // namespace
 
-#if ((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99) \
-     && !defined(_GLIBCXX_HAVE_BROKEN_VSWPRINTF))
+#if ((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99))
 
 #include <ext/string_conversions.h>
 
@@ -2961,6 +2960,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
   { return __gnu_cxx::__stoa(&std::wcstold, "stold", __str.c_str(), __idx); }
 
   // DR 1261.
+#ifndef _GLIBCXX_HAVE_BROKEN_VSWPRINTF
   inline wstring
   to_wstring(int __val)
   { return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, 4 * sizeof(int),
@@ -3021,6 +3021,7 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
     return __gnu_cxx::__to_xstring<wstring>(&std::vswprintf, __n,
 					    L"%Lf", __val);
   }
+#endif // _GLIBCXX_HAVE_BROKEN_VSWPRINTF
 #endif
 
 _GLIBCXX_END_NAMESPACE_VERSION
