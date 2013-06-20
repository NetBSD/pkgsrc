$NetBSD: patch-glib2_ext_glib2_rbgobject.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- glib2/ext/glib2/rbgobject.c.orig	2013-05-08 15:01:55.000000000 +0000
+++ glib2/ext/glib2/rbgobject.c
@@ -182,7 +182,7 @@ rbgobj_add_relative(VALUE obj, VALUE rel
     if (RVAL2CBOOL(rb_ivar_defined(obj, id_relatives)))
         hash = rb_ivar_get(obj, id_relatives);
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+    if (NIL_P(hash) || TYPE(hash) != T_HASH) {
         hash = rb_hash_new();
         rb_ivar_set(obj, id_relatives, hash);
     }
@@ -206,7 +206,7 @@ rbgobj_add_relative_removable(VALUE obj,
     if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
         hash = rb_ivar_get(obj, obj_ivar_id);
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+    if (NIL_P(hash) || TYPE(hash) != T_HASH) {
         hash = rb_hash_new();
         rb_ivar_set(obj, obj_ivar_id, hash);
     }
@@ -221,7 +221,7 @@ rbgobj_get_relative_removable(VALUE obj,
     if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
         hash = rb_ivar_get(obj, obj_ivar_id);
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+    if (NIL_P(hash) || TYPE(hash) != T_HASH) {
         return Qnil;
     }
     return rb_hash_aref(hash, hash_key);
@@ -235,7 +235,7 @@ rbgobj_remove_relative(VALUE obj, ID obj
     if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
         hash = rb_ivar_get(obj, obj_ivar_id);
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+    if (NIL_P(hash) || TYPE(hash) != T_HASH) {
         /* should not happen. */
     } else {
         rb_funcall(hash, id_delete, 1, hash_key);
