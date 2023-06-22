$NetBSD: patch-Include_pymacro.h,v 1.1 2023/06/22 11:16:06 jperkin Exp $

Do not define static_assert in C++ code.

--- Include/pymacro.h.orig	2023-06-06 22:00:27.000000000 +0000
+++ Include/pymacro.h
@@ -19,7 +19,7 @@
 // not C++, and only for C11-17.
 #if !defined(static_assert) && (defined(__GNUC__) || defined(__clang__)) \
      && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L \
-     && __STDC_VERSION__ <= 201710L
+     && __STDC_VERSION__ <= 201710L && !defined(__cplusplus)
 #  define static_assert _Static_assert
 #endif
 
