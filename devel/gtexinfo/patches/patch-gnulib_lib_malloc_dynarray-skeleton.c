$NetBSD: patch-gnulib_lib_malloc_dynarray-skeleton.c,v 1.1 2021/12/10 13:55:31 joerg Exp $

Macro conflicts with glibc 2.34.

--- gnulib/lib/malloc/dynarray-skeleton.c.orig	2021-12-10 13:51:47.386493429 +0000
+++ gnulib/lib/malloc/dynarray-skeleton.c
@@ -103,6 +103,10 @@
 # error "DYNARRAY_PREFIX must be defined"
 #endif
 
+#undef __attribute_nonnull__
+#define __attribute_nonnull__(x)
+
+
 #ifdef DYNARRAY_INITIAL_SIZE
 # if DYNARRAY_INITIAL_SIZE < 0
 #  error "DYNARRAY_INITIAL_SIZE must be non-negative"
