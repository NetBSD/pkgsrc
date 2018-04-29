$NetBSD: patch-ext_glib2_rbgobj__closure.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgobj_closure.c.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgobj_closure.c
@@ -1,6 +1,6 @@
 /* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
 /*
- *  Copyright (C) 2011-2016  Ruby-GNOME2 Project Team
+ *  Copyright (C) 2011-2018  Ruby-GNOME2 Project Team
  *  Copyright (C) 2002-2006  Ruby-GNOME2 Project
  *  Copyright (C) 2002,2003  Masahiro Sakai
  *
@@ -191,8 +191,9 @@ rclosure_invalidate(G_GNUC_UNUSED gpoint
         for (next = rclosure->objects; next; next = next->next) {
             GObject *object = G_OBJECT(next->data);
             VALUE obj = rbgobj_ruby_object_from_instance2(object, FALSE);
-            if (!NIL_P(rclosure->rb_holder) && !NIL_P(obj))
-                G_REMOVE_RELATIVE(obj, id_closures, rclosure->rb_holder);
+            if (!NIL_P(rclosure->rb_holder) && !NIL_P(obj)) {
+                rbgobj_object_remove_relative(obj, rclosure->rb_holder);
+            }
         }
 
         rclosure_unref(rclosure);
@@ -286,16 +287,15 @@ rclosure_weak_notify(gpointer data, GObj
 void
 g_rclosure_attach(GClosure *closure, VALUE object)
 {
-    static VALUE mGLibObject = (VALUE)NULL;
+    static VALUE cGLibObject = Qnil;
     GRClosure *rclosure = (GRClosure *)closure;
 
-    G_RELATIVE2(object, Qnil, id_closures, rclosure->rb_holder);
-
-    if (!mGLibObject) {
-        mGLibObject = rb_const_get(mGLib, rb_intern("Object"));
+    if (NIL_P(cGLibObject)) {
+        cGLibObject = rb_const_get(mGLib, rb_intern("Object"));
     }
-    if (rb_obj_is_kind_of(object, mGLibObject)) {
+    if (rb_obj_is_kind_of(object, cGLibObject)) {
         GObject *gobject;
+        rbgobj_object_add_relative(object, rclosure->rb_holder);
         gobject = RVAL2GOBJ(object);
         rclosure->count++;
         g_object_weak_ref(gobject, rclosure_weak_notify, rclosure);
