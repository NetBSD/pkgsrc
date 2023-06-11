$NetBSD: patch-gnulib-m4_assert__h.m4,v 1.1 2023/06/11 00:59:27 schmonz Exp $

Borrow upstream gnulib commit 0814a293:
Make static_assert work on Solaris 11.4.

--- gnulib-m4/assert_h.m4.orig	2022-10-15 19:19:56.000000000 +0000
+++ gnulib-m4/assert_h.m4
@@ -57,5 +57,11 @@ AC_DEFUN([gl_ASSERT_H],
              && __GNUG__ < 6 && __clang_major__ < 6)))
  #include <assert.h>
  #undef/**/assert
+ /* Solaris 11.4 <assert.h> defines static_assert as a macro with 2 arguments.
+    We need it also to be invocable with a single argument.  */
+ #if defined __sun && (__STDC_VERSION__ - 0 >= 201112L) && !defined __cplusplus
+  #undef static_assert
+  #define static_assert _Static_assert
+ #endif
 #endif])
 ])
