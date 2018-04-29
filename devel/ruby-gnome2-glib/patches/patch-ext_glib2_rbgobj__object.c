$NetBSD: patch-ext_glib2_rbgobj__object.c,v 1.1 2018/04/29 15:36:44 tsutsui Exp $

- pull upstream fix for issue #1162

--- ext/glib2/rbgobj_object.c.orig	2018-04-29 15:03:30.000000000 +0000
+++ ext/glib2/rbgobj_object.c
@@ -43,7 +43,8 @@ weak_notify(gpointer data, G_GNUC_UNUSED
     gobj_holder *holder = data;
 
     rbgobj_instance_call_cinfo_free(holder->gobj);
-    rbgobj_invalidate_relatives(holder->self);
+    g_hash_table_unref(holder->rb_relatives);
+    holder->rb_relatives = NULL;
     holder->destroyed = TRUE;
 
     g_object_unref(holder->gobj);
@@ -51,11 +52,24 @@ weak_notify(gpointer data, G_GNUC_UNUSED
 }
 
 static void
+holder_relatives_mark(gpointer key, gpointer value, gpointer user_data)
+{
+    VALUE rb_relative = (VALUE)value;
+    rb_gc_mark(rb_relative);
+}
+
+static void
 holder_mark(void *data)
 {
     gobj_holder *holder = data;
-    if (holder->gobj && !holder->destroyed)
-        rbgobj_instance_call_cinfo_mark(holder->gobj);
+
+    if (!holder->gobj)
+        return;
+    if (holder->destroyed)
+        return;
+
+    rbgobj_instance_call_cinfo_mark(holder->gobj);
+    g_hash_table_foreach(holder->rb_relatives, holder_relatives_mark, NULL);
 }
 
 static void
@@ -91,6 +105,59 @@ static const rb_data_type_t rg_glib_obje
     RUBY_TYPED_FREE_IMMEDIATELY,
 };
 
+void
+rbgobj_object_add_relative(VALUE rb_gobject, VALUE rb_relative)
+{
+    gobj_holder *holder;
+    TypedData_Get_Struct(rb_gobject,
+                         gobj_holder,
+                         &rg_glib_object_type,
+                         holder);
+    if (holder->rb_relatives) {
+        g_hash_table_insert(holder->rb_relatives,
+                            (gpointer)(rb_relative),
+                            (gpointer)(rb_relative));
+    }
+}
+
+void
+rbgobj_object_remove_relative(VALUE rb_gobject, VALUE rb_relative)
+{
+    gobj_holder *holder;
+    TypedData_Get_Struct(rb_gobject,
+                         gobj_holder,
+                         &rg_glib_object_type,
+                         holder);
+    if (holder->rb_relatives) {
+        g_hash_table_remove(holder->rb_relatives,
+                            (gpointer)(rb_relative));
+    }
+}
+
+static gboolean
+rbgobj_object_remove_relatives_body(gpointer key,
+                                    gpointer value,
+                                    gpointer user_data)
+{
+    VALUE rb_relative = (VALUE)value;
+    VALUE rb_relative_class = (VALUE)user_data;
+
+    return RVAL2CBOOL(rb_obj_is_kind_of(rb_relative, rb_relative_class));
+}
+
+void
+rbgobj_object_remove_relatives(VALUE rb_gobject, VALUE rb_relative_class)
+{
+    gobj_holder *holder;
+    TypedData_Get_Struct(rb_gobject,
+                         gobj_holder,
+                         &rg_glib_object_type,
+                         holder);
+    g_hash_table_foreach_remove(holder->rb_relatives,
+                                rbgobj_object_remove_relatives_body,
+                                (gpointer)(rb_relative_class));
+}
+
 VALUE
 rbgobj_object_alloc_func(VALUE klass)
 {
@@ -105,6 +172,7 @@ rbgobj_object_alloc_func(VALUE klass)
     holder->gobj  = NULL;
     holder->cinfo = NULL;
     holder->destroyed = FALSE;
+    holder->rb_relatives = g_hash_table_new(g_direct_hash, g_direct_equal);
 
     return result;
 }
@@ -686,13 +754,6 @@ static void
 rg_destroy_bind_property_full_data(gpointer user_data)
 {
     RGBindPropertyCallbackData *data = (RGBindPropertyCallbackData *)user_data;
-
-    if (!NIL_P(data->transform_to_callback))
-        G_CHILD_REMOVE(data->self, data->transform_to_callback);
-
-    if (!NIL_P(data->transform_from_callback))
-        G_CHILD_REMOVE(data->self, data->transform_from_callback);
-
     xfree(data);
 }
 
@@ -715,6 +776,7 @@ rg_bind_property(gint argc, VALUE *argv,
     GBinding *binding;
     GBindingTransformFunc transform_to = NULL;
     GBindingTransformFunc transform_from = NULL;
+    VALUE rb_binding;
 
     rb_scan_args(argc, argv, "41", &rb_source_property, &rb_target,
                  &rb_target_property, &rb_flags, &rb_options);
@@ -731,18 +793,16 @@ rg_bind_property(gint argc, VALUE *argv,
     flags = RVAL2GBINDINGFLAGS(rb_flags);
 
     if (!NIL_P(rb_transform_to)) {
-        G_CHILD_ADD(self, rb_transform_to);
         transform_to = rg_bind_property_transform_to_callback;
     }
 
     if (!NIL_P(rb_transform_from)) {
-        G_CHILD_ADD(self, rb_transform_from);
         transform_from = rg_bind_property_transform_from_callback;
     }
 
     if (transform_to || transform_from) {
         RGBindPropertyCallbackData *data;
-        data = (RGBindPropertyCallbackData *)xmalloc(sizeof(RGBindPropertyCallbackData));
+        data = RB_ALLOC(RGBindPropertyCallbackData);
         data->self = self;
         data->transform_to_callback = rb_transform_to;
         data->transform_from_callback = rb_transform_from;
@@ -752,13 +812,21 @@ rg_bind_property(gint argc, VALUE *argv,
                                               transform_from,
                                               (gpointer)data,
                                               rg_destroy_bind_property_full_data);
+        rb_binding = GOBJ2RVAL(binding);
+        if (!NIL_P(rb_transform_to)) {
+            rbgobj_object_add_relative(rb_binding, rb_transform_to);
+        }
+        if (!NIL_P(rb_transform_from)) {
+            rbgobj_object_add_relative(rb_binding, rb_transform_from);
+        }
     } else {
         binding = g_object_bind_property(source, source_property,
                                          target, target_property,
                                          flags);
+        rb_binding = GOBJ2RVAL(binding);
     }
 
-    return GOBJ2RVAL(binding);
+    return rb_binding;
 }
 #endif
 
