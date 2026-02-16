$NetBSD: patch-src_include_R__ext_Error.h,v 1.5 2026/02/16 23:44:02 mef Exp $

Fix building with C++.

--- src/include/R_ext/Error.h.orig	2025-04-22 07:15:01.000000000 +0900
+++ src/include/R_ext/Error.h	2026-01-03 18:52:17.619139182 +0900
@@ -39,7 +39,8 @@ extern "C" {
  * OTOH, '_Noreturn' is an obsolescent (in C23) function specifier.
  */
 #if defined NORET
-#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L)
+#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L) || \
+      (defined(__cplusplus) && __cplusplus >= 201103L)
 // gcc 15 LLVM clang 19- and Apple clang 17
 # define NORET [[noreturn]]
 #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201102L
