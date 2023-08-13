$NetBSD: patch-src_helper_mathfns.h,v 1.1 2023/08/13 14:13:23 ryoon Exp $

* NetBSD defines rounddown() and roundup() macros.

--- src/helper/mathfns.h.orig	2022-10-04 18:03:23.000000000 +0000
+++ src/helper/mathfns.h
@@ -77,6 +77,7 @@ T constexpr safemod(T a, T b)
     return a < 0 ? a + b : a;
 }
 
+#undef rounddown
 /// Returns \a a rounded down to the nearest multiple of \a b, assuming b >= 1.
 template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
 T constexpr rounddown(T a, T b)
@@ -84,6 +85,7 @@ T constexpr rounddown(T a, T b)
     return a - safemod(a, b);
 }
 
+#undef roundup
 /// Returns \a a rounded up to the nearest multiple of \a b, assuming b >= 1.
 template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
 T constexpr roundup(T a, T b)
