$NetBSD: patch-gobject-introspection_ext_gobject-introspection_rb-gi-struct-info.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- gobject-introspection/ext/gobject-introspection/rb-gi-struct-info.c.orig	2013-03-17 09:57:52.000000000 +0000
+++ gobject-introspection/ext/gobject-introspection/rb-gi-struct-info.c
@@ -119,7 +119,7 @@ rg_get_method(VALUE self, VALUE rb_n_or_
     GIFunctionInfo *function_info;
 
     info = SELF(self);
-    if (RB_TYPE_P(rb_n_or_name, RUBY_T_FIXNUM)) {
+    if (RB_TYPE_P(rb_n_or_name, T_FIXNUM)) {
         gint n;
         n = NUM2INT(rb_n_or_name);
         function_info = g_struct_info_get_method(info, n);
