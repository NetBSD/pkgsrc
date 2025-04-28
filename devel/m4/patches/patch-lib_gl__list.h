$NetBSD: patch-lib_gl__list.h,v 1.1 2025/04/28 17:24:43 tnn Exp $

Move [[__nodiscard__]] to beginning of row.
Required for C23.

--- lib/gl_list.h.orig	2025-04-28 17:20:07.433022820 +0000
+++ lib/gl_list.h
@@ -630,7 +630,7 @@ gl_list_node_value (gl_list_t list, gl_l
          ->node_value (list, node);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD int
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE int
 gl_list_node_nx_set_value (gl_list_t list, gl_list_node_t node,
                            const void *elt)
 {
@@ -685,20 +685,20 @@ gl_list_get_last (gl_list_t list)
   return gl_list_get_at (list, gl_list_size (list) - 1);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_set_at (gl_list_t list, size_t position, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
          ->nx_set_at (list, position, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_set_first (gl_list_t list, const void *elt)
 {
   return gl_list_nx_set_at (list, 0, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_set_last (gl_list_t list, const void *elt)
 {
   return gl_list_nx_set_at (list, gl_list_size (list) - 1, elt);
@@ -752,35 +752,35 @@ gl_list_indexof_from_to (gl_list_t list,
          ->indexof_from_to (list, start_index, end_index, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_add_first (gl_list_t list, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
          ->nx_add_first (list, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_add_last (gl_list_t list, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
          ->nx_add_last (list, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
          ->nx_add_before (list, node, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
          ->nx_add_after (list, node, elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_list_nx_add_at (gl_list_t list, size_t position, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
@@ -891,7 +891,7 @@ gl_sortedlist_indexof_from_to (gl_list_t
                                        elt);
 }
 
-GL_LIST_INLINE _GL_ATTRIBUTE_NODISCARD gl_list_node_t
+_GL_ATTRIBUTE_NODISCARD GL_LIST_INLINE gl_list_node_t
 gl_sortedlist_nx_add (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
 {
   return ((const struct gl_list_impl_base *) list)->vtable
