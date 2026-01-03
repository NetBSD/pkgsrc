$NetBSD: patch-src_include_R__ext_Error.h,v 1.4 2026/01/03 09:17:26 mef Exp $

Fix building with C++.

--- src/include/R_ext/Error.h.orig	2025-01-19 08:15:01.000000000 +0900
+++ src/include/R_ext/Error.h	2026-01-03 08:54:10.539893482 +0900
@@ -45,7 +45,8 @@
  * In C11 there is _Noreturn * (or noreturn in header <stdnoreturn.h>).
  */
 #if defined NORET
-#elif (defined(__clang__) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L)
+#elif (defined(__clang__) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L) || \
+      (defined(__cplusplus) && __cplusplus >= 201103L)
 # define NORET [[noreturn]]
 #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201102L
 # define NORET _Noreturn
