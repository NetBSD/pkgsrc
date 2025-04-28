$NetBSD: patch-lib_gl__oset.h,v 1.1 2025/04/28 17:24:43 tnn Exp $

Move [[__nodiscard__]] to beginning of row.
Required for C23.

--- lib/gl_oset.h.orig	2025-04-28 17:19:25.736258687 +0000
+++ lib/gl_oset.h
@@ -272,7 +272,7 @@ gl_oset_search_atleast (gl_oset_t set,
          ->search_atleast (set, threshold_fn, threshold, eltp);
 }
 
-GL_OSET_INLINE _GL_ATTRIBUTE_NODISCARD int
+_GL_ATTRIBUTE_NODISCARD GL_OSET_INLINE int
 gl_oset_nx_add (gl_oset_t set, const void *elt)
 {
   return ((const struct gl_oset_impl_base *) set)->vtable->nx_add (set, elt);
