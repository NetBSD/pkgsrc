$NetBSD: patch-ext_gobject-introspection_rb-gi-function-info.c,v 1.3 2018/07/06 18:15:40 tsutsui Exp $

- pull upstream fix for a memory leak
 https://github.com/ruby-gnome2/ruby-gnome2/issues/1230
 https://github.com/ruby-gnome2/ruby-gnome2/issues/1231

--- ext/gobject-introspection/rb-gi-function-info.c.orig	2018-07-04 13:25:47.843178241 +0000
+++ ext/gobject-introspection/rb-gi-function-info.c
@@ -46,6 +46,7 @@ struct RBGICallbackData_ {
     RBGICallback *callback;
     RBGIArgMetadata *metadata;
     VALUE rb_callback;
+    VALUE rb_owner;
 };
 
 static VALUE RG_TARGET_NAMESPACE;
@@ -304,18 +305,6 @@ fill_metadata(GPtrArray *args_metadata, 
 }
 
 static void
-callback_data_guard_from_gc(RBGICallbackData *callback_data)
-{
-    rbg_gc_guard(callback_data, callback_data->rb_callback);
-}
-
-static void
-callback_data_unguard_from_gc(RBGICallbackData *callback_data)
-{
-    rbg_gc_unguard(callback_data);
-}
-
-static void
 rb_gi_callback_free(RBGICallback *callback)
 {
     g_callable_info_free_closure(callback->callback_info,
@@ -325,13 +314,28 @@ rb_gi_callback_free(RBGICallback *callba
     xfree(callback);
 }
 
+static void
+rb_gi_callback_data_weak_notify(gpointer data, GObject* where_the_object_was)
+{
+    RBGICallbackData *callback_data = data;
+    callback_data->rb_owner = Qnil;
+}
+
 void
 rb_gi_callback_data_free(RBGICallbackData *callback_data)
 {
     if (callback_data->callback) {
         rb_gi_callback_free(callback_data->callback);
     }
-    callback_data_unguard_from_gc(callback_data);
+    if (!NIL_P(callback_data->rb_owner)) {
+        GObject *gobject;
+        gobject = RVAL2GOBJ(callback_data->rb_owner);
+        g_object_weak_unref(gobject,
+                            rb_gi_callback_data_weak_notify,
+                            callback_data);
+        rbgobj_object_remove_relative(callback_data->rb_owner,
+                                      callback_data->rb_callback);
+    }
     xfree(callback_data->metadata);
     xfree(callback_data);
 }
@@ -349,7 +353,7 @@ rb_gi_callback_data_get_rb_callback(RBGI
 }
 
 static void
-destroy_notify(gpointer data)
+rb_gi_callback_data_destroy_notify(gpointer data)
 {
     RBGICallbackData *callback_data = data;
     rb_gi_callback_data_free(callback_data);
@@ -1087,7 +1091,10 @@ ffi_closure_callback(G_GNUC_UNUSED ffi_c
 }
 
 static void
-in_callback_argument_from_ruby(RBGIArgMetadata *metadata, GArray *in_args)
+in_callback_argument_from_ruby(RBGIArgMetadata *metadata,
+                               GArray *in_args,
+                               VALUE self,
+                               VALUE rb_arguments)
 {
     gpointer callback_function;
     GIArgInfo *arg_info;
@@ -1145,12 +1152,25 @@ in_callback_argument_from_ruby(RBGIArgMe
         callback_data->callback = callback;
         callback_data->metadata = metadata;
         callback_data->rb_callback = rb_block_proc();
-        callback_data_guard_from_gc(callback_data);
+        if (NIL_P(self)) {
+            callback_data->rb_owner = rb_ary_entry(rb_arguments, 0);
+        } else {
+            callback_data->rb_owner = self;
+        }
+        rbgobj_object_add_relative(callback_data->rb_owner,
+                                   callback_data->rb_callback);
+        {
+            GObject *gobject;
+            gobject = RVAL2GOBJ(callback_data->rb_owner);
+            g_object_weak_ref(gobject,
+                              rb_gi_callback_data_weak_notify,
+                              callback_data);
+        }
         closure_argument->v_pointer = callback_data;
     }
 
     if (destroy_argument) {
-        destroy_argument->v_pointer = destroy_notify;
+        destroy_argument->v_pointer = rb_gi_callback_data_destroy_notify;
     }
 }
 
@@ -1163,7 +1183,7 @@ in_argument_from_ruby(GICallableInfo *ca
                       VALUE self)
 {
     if (metadata->callback_p && !metadata->destroy_p) {
-        in_callback_argument_from_ruby(metadata, in_args);
+        in_callback_argument_from_ruby(metadata, in_args, self, rb_arguments);
         return;
     }
 
