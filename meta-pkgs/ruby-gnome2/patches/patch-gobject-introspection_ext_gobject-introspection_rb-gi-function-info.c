$NetBSD: patch-gobject-introspection_ext_gobject-introspection_rb-gi-function-info.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- gobject-introspection/ext/gobject-introspection/rb-gi-function-info.c.orig	2013-05-24 14:43:47.000000000 +0000
+++ gobject-introspection/ext/gobject-introspection/rb-gi-function-info.c
@@ -627,7 +627,7 @@ rb_gi_function_info_invoke_raw(GIFunctio
     gboolean unlock_gvl = FALSE;
     VALUE rb_receiver, rb_arguments, rb_unlock_gvl;
 
-    if (RB_TYPE_P(rb_options, RUBY_T_ARRAY)) {
+    if (RB_TYPE_P(rb_options, T_ARRAY)) {
         rb_receiver = Qnil;
         rb_arguments = rb_options;
         rb_unlock_gvl = Qnil;
