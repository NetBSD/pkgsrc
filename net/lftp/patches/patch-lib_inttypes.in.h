$NetBSD: patch-lib_inttypes.in.h,v 1.3 2020/01/08 12:38:08 nia Exp $

Poratbility obstacle.

--- lib/inttypes.in.h.orig	2019-12-21 07:27:17.000000000 +0000
+++ lib/inttypes.in.h
@@ -56,10 +56,6 @@
 # include <stdio.h>
 #endif
 
-#if !(INT_MAX == 0x7fffffff && INT_MIN + INT_MAX == -1)
-# error "This file assumes that 'int' is 32-bit two's complement. Please report your platform and compiler to <bug-gnulib@gnu.org>."
-#endif
-
 /* The definitions of _GL_FUNCDECL_RPL etc. are copied here.  */
 
 /* The definition of _GL_ARG_NONNULL is copied here.  */
