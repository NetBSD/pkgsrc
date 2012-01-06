$NetBSD: patch-glib2_ext_glib2_rbgobj__closure.c,v 1.1 2012/01/06 13:34:50 obache Exp $

* fix SEGV by GC on Ruby 1.9.
  https://github.com/ruby-gnome2/ruby-gnome2/commit/b5ca012f55017dff95546d331aa87576432fbc32
  https://github.com/ruby-gnome2/ruby-gnome2/commit/7c712c51181edc73d419007a31064321bd14c929

--- glib2/ext/glib2/rbgobj_closure.c.orig	2011-09-18 02:48:35.000000000 +0000
+++ glib2/ext/glib2/rbgobj_closure.c
@@ -148,8 +148,7 @@ rclosure_unref(GRClosure *rclosure)
         g_list_free(rclosure->objects);
         rclosure->objects = NULL;
         if (!NIL_P(rclosure->rb_holder)) {
-            RDATA(rclosure->rb_holder)->dmark = NULL;
-            RDATA(rclosure->rb_holder)->dfree = NULL;
+            DATA_PTR(rclosure->rb_holder) = NULL;
             rclosure->rb_holder = Qnil;
         }
     }
@@ -178,13 +177,18 @@ rclosure_invalidate(gpointer data, GClos
 static void
 gr_closure_holder_mark(GRClosure *rclosure)
 {
-    rb_gc_mark(rclosure->callback);
-    rb_gc_mark(rclosure->extra_args);
+    if (rclosure) {
+        rb_gc_mark(rclosure->callback);
+        rb_gc_mark(rclosure->extra_args);
+    }
 }
 
 static void
 gr_closure_holder_free(GRClosure *rclosure)
 {
+    if (!rclosure)
+	return;
+
     if (rclosure->count > 0) {
         rclosure->count = 1;
 
