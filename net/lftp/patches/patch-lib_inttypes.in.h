$NetBSD: patch-lib_inttypes.in.h,v 1.1 2013/05/18 20:23:03 adam Exp $

Poratbility obstacle.

--- lib/inttypes.in.h.orig	2013-05-18 20:12:09.000000000 +0000
+++ lib/inttypes.in.h
@@ -52,9 +52,6 @@
 /* Get CHAR_BIT.  */
 #include <limits.h>
 
-#if !(INT_MIN == INT32_MIN && INT_MAX == INT32_MAX)
-# error "This file assumes that 'int' has exactly 32 bits. Please report your platform and compiler to <bug-gnulib@gnu.org>."
-#endif
 
 /* The definitions of _GL_FUNCDECL_RPL etc. are copied here.  */
 
