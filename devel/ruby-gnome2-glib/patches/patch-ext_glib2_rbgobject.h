$NetBSD: patch-ext_glib2_rbgobject.h,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgobject.h.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgobject.h
@@ -79,6 +79,7 @@ RUBY_GLIB2_VAR  ID rbgobj_id_children;
     (rbgobj_add_relative_removable(self, Qnil, rbgobj_id_children, child))
 #define G_CHILD_REMOVE(self, child) \
     (rbgobj_remove_relative(self, rbgobj_id_children, child))
+/* Deprecated since 3.2.5. Use rbobj_object_remove_relatives() instead. */
 #define G_CHILD_REMOVE_ALL(self) \
     (rbgobj_remove_relative_all(self, rbgobj_id_children))
 
@@ -147,6 +148,13 @@ extern VALUE rbgobj_ruby_object_from_ins
 extern VALUE rbgobj_ruby_object_from_instance_with_unref(gpointer instance);
 extern void rbgobj_instance_unref(gpointer instance);
 
+extern void rbgobj_object_add_relative(VALUE rb_gobject,
+                                       VALUE rb_relative);
+extern void rbgobj_object_remove_relative(VALUE rb_gobject,
+                                          VALUE rb_relative);
+extern void rbgobj_object_remove_relatives(VALUE rb_gobject,
+                                           VALUE rb_relative_class);
+
 extern void rbgobj_add_relative(VALUE obj, VALUE relative);
 extern void rbgobj_invalidate_relatives(VALUE obj);
 extern void rbgobj_add_relative_removable(VALUE obj, VALUE relative,
