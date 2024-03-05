$NetBSD: patch-src_include_R__ext_Error.h,v 1.1 2024/03/05 16:12:33 jperkin Exp $

Fix building with C++.

--- src/include/R_ext/Error.h.orig	2024-03-05 16:09:06.557665563 +0000
+++ src/include/R_ext/Error.h
@@ -35,7 +35,8 @@ extern "C" {
  * In C11 there is _Noreturn * (or noreturn in header <stdnoreturn.h>).
  */
 #if defined NORET
-#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L)
+#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202301L) || \
+      (defined(__cplusplus) && __cplusplus >= 201103L)
 # define NORET [[noreturn]]
 #elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201102L
 # define NORET _Noreturn
