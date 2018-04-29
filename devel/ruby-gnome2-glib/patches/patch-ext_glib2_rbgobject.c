$NetBSD: patch-ext_glib2_rbgobject.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgobject.c.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgobject.c
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2011  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2011-2018  Ruby-GNOME2 Project Team
  *  Copyright (C) 2003-2006  Ruby-GNOME2 Project Team
  *  Copyright (C) 2002,2003  Masahiro Sakai
  *  Copyright (C) 1998-2000 Yukihiro Matsumoto,
@@ -183,16 +183,25 @@ rbgobj_ruby_object_from_instance_with_un
 void
 rbgobj_add_relative(VALUE obj, VALUE relative)
 {
-    VALUE hash = Qnil;
+    static VALUE mGLibObject = Qnil;
+    if (NIL_P(mGLibObject)) {
+        mGLibObject = rb_const_get(mGLib, rb_intern("Object"));
+    }
 
-    if (RVAL2CBOOL(rb_ivar_defined(obj, id_relatives)))
-        hash = rb_ivar_get(obj, id_relatives);
+    if (rb_obj_is_kind_of(obj, mGLibObject)) {
+        rbgobj_object_add_relative(obj, relative);
+    } else {
+        VALUE hash = Qnil;
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
-        hash = rb_hash_new();
-        rb_ivar_set(obj, id_relatives, hash);
+        if (RVAL2CBOOL(rb_ivar_defined(obj, id_relatives)))
+            hash = rb_ivar_get(obj, id_relatives);
+
+        if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+            hash = rb_hash_new();
+            rb_ivar_set(obj, id_relatives, hash);
+        }
+        rb_hash_aset(hash, relative, Qnil);
     }
-    rb_hash_aset(hash, relative, Qnil);
 }
 
 void
@@ -207,16 +216,26 @@ rbgobj_invalidate_relatives(VALUE obj)
 void
 rbgobj_add_relative_removable(VALUE obj, VALUE relative, ID obj_ivar_id, VALUE hash_key)
 {
-    VALUE hash = Qnil;
+    static VALUE cGLibObject = Qnil;
+    if (NIL_P(cGLibObject)) {
+        cGLibObject = rb_const_get(mGLib, rb_intern("Object"));
+    }
 
-    if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
-        hash = rb_ivar_get(obj, obj_ivar_id);
+    if (obj_ivar_id == rbgobj_id_children &&
+        rb_obj_is_kind_of(obj, cGLibObject)) {
+        rbgobj_object_add_relative(obj, hash_key);
+    } else {
+        VALUE hash = Qnil;
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
-        hash = rb_hash_new();
-        rb_ivar_set(obj, obj_ivar_id, hash);
+        if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
+            hash = rb_ivar_get(obj, obj_ivar_id);
+
+        if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+            hash = rb_hash_new();
+            rb_ivar_set(obj, obj_ivar_id, hash);
+        }
+        rb_hash_aset(hash, hash_key, relative);
     }
-    rb_hash_aset(hash, hash_key, relative);
 }
 
 VALUE
@@ -236,15 +255,25 @@ rbgobj_get_relative_removable(VALUE obj,
 void
 rbgobj_remove_relative(VALUE obj, ID obj_ivar_id, VALUE hash_key)
 {
-    VALUE hash = Qnil;
-
-    if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
-        hash = rb_ivar_get(obj, obj_ivar_id);
+    static VALUE cGLibObject = Qnil;
+    if (NIL_P(cGLibObject)) {
+        cGLibObject = rb_const_get(mGLib, rb_intern("Object"));
+    }
 
-    if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
-        /* should not happen. */
+    if ((obj_ivar_id == id_relatives || obj_ivar_id == rbgobj_id_children) &&
+        rb_obj_is_kind_of(obj, cGLibObject)) {
+        rbgobj_object_remove_relative(obj, hash_key);
     } else {
-        rb_funcall(hash, id_delete, 1, hash_key);
+        VALUE hash = Qnil;
+
+        if (RVAL2CBOOL(rb_ivar_defined(obj, obj_ivar_id)))
+            hash = rb_ivar_get(obj, obj_ivar_id);
+
+        if (NIL_P(hash) || TYPE(hash) != RUBY_T_HASH) {
+            /* should not happen. */
+        } else {
+            rb_funcall(hash, id_delete, 1, hash_key);
+        }
     }
 }
 
