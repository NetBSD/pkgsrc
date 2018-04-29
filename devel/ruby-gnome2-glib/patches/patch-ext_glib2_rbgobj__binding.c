$NetBSD: patch-ext_glib2_rbgobj__binding.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgobj_binding.c.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgobj_binding.c
@@ -28,7 +28,15 @@
 static VALUE
 rg_unbind(VALUE self)
 {
-    g_binding_unbind(_SELF(self));
+    GBinding *binding = _SELF(self);
+    GObject *source;
+    VALUE rb_source;
+
+    source = g_binding_get_source(binding);
+    rb_source = GOBJ2RVAL(source);
+    rbgobj_object_remove_relative(rb_source, self);
+    g_binding_unbind(binding);
+
     return self;
 }
 #endif
