$NetBSD: patch-lib_inttypes.in.h,v 1.2 2015/07/25 03:29:57 ryoon Exp $

Poratbility obstacle.

--- lib/inttypes.in.h.orig	2015-05-27 08:37:01.000000000 +0000
+++ lib/inttypes.in.h
@@ -56,9 +56,6 @@
 # include <stdio.h>
 #endif
 
-#if !(INT_MIN == INT32_MIN && INT_MAX == INT32_MAX)
-# error "This file assumes that 'int' has exactly 32 bits. Please report your platform and compiler to <bug-gnulib@gnu.org>."
-#endif
 
 /* The definitions of _GL_FUNCDECL_RPL etc. are copied here.  */
 
