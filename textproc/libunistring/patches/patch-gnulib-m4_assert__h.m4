$NetBSD: patch-gnulib-m4_assert__h.m4,v 1.2 2024/02/25 15:13:59 wiz Exp $

Borrow upstream gnulib commit 0814a293:
Make static_assert work on Solaris 11.4.

--- gnulib-m4/assert_h.m4.orig	2024-01-29 00:58:08.000000000 +0000
+++ gnulib-m4/assert_h.m4
@@ -60,6 +60,12 @@ AC_DEFUN([gl_ASSERT_H],
              && __GNUG__ < 6 && __clang_major__ < 6)))
  #include <assert.h>
  #undef/**/assert
+ /* Solaris 11.4 <assert.h> defines static_assert as a macro with 2 arguments.
+    We need it also to be invocable with a single argument.  */
+ #if defined __sun && (__STDC_VERSION__ - 0 >= 201112L) && !defined __cplusplus
+  #undef static_assert
+  #define static_assert _Static_assert
+ #endif
  #ifdef __sgi
   #undef/**/__ASSERT_H__
  #endif
