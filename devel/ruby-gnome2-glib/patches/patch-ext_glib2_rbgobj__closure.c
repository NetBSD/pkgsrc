$NetBSD: patch-ext_glib2_rbgobj__closure.c,v 1.3 2018/05/26 15:58:59 tsutsui Exp $

- pull upstream fix for issue #1166
 https://github.com/ruby-gnome2/ruby-gnome2/commit/e11ae27581af70fb09ce26ef038d8ebfac49047a
 https://github.com/ruby-gnome2/ruby-gnome2/commit/e77f03b60045c40b9851cc9ef5195c168c674fd0

--- ext/glib2/rbgobj_closure.c.orig	2018-05-04 23:58:14.749953854 +0000
+++ ext/glib2/rbgobj_closure.c
@@ -290,12 +290,13 @@ g_rclosure_attach(GClosure *closure, VALUE object)
     static VALUE cGLibObject = Qnil;
     GRClosure *rclosure = (GRClosure *)closure;
 
+    rbgobj_add_relative(object, rclosure->rb_holder);
+
     if (NIL_P(cGLibObject)) {
         cGLibObject = rb_const_get(mGLib, rb_intern("Object"));
     }
     if (rb_obj_is_kind_of(object, cGLibObject)) {
         GObject *gobject;
-        rbgobj_object_add_relative(object, rclosure->rb_holder);
         gobject = RVAL2GOBJ(object);
         rclosure->count++;
         g_object_weak_ref(gobject, rclosure_weak_notify, rclosure);
