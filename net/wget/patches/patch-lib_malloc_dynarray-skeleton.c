$NetBSD: patch-lib_malloc_dynarray-skeleton.c,v 1.1 2021/01/14 16:31:00 schmonz Exp $

Use the macro used elsewhere to fix build on at least macOS.

--- lib/malloc/dynarray-skeleton.c.orig	2021-01-14 16:23:44.000000000 +0000
+++ lib/malloc/dynarray-skeleton.c
@@ -192,6 +192,10 @@ DYNARRAY_NAME (free__array__) (struct DY
 
 /* Initialize a dynamic array object.  This must be called before any
    use of the object.  */
+#ifdef __nonnull
+#undef __nonnull
+#define __nonnull(params) _GL_ARG_NONNULL(params)
+#endif
 __nonnull ((1))
 static void
 DYNARRAY_NAME (init) (struct DYNARRAY_STRUCT *list)
