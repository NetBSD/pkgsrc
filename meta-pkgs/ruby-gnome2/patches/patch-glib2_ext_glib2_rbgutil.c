$NetBSD: patch-glib2_ext_glib2_rbgutil.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- glib2/ext/glib2/rbgutil.c.orig	2013-05-26 03:25:49.000000000 +0000
+++ glib2/ext/glib2/rbgutil.c
@@ -62,7 +62,7 @@ rbgutil_set_properties(VALUE self, VALUE
     VALUE ary;
     GObject* obj;
 
-    Check_Type(hash, RUBY_T_HASH);
+    Check_Type(hash, T_HASH);
     ary = rb_funcall(hash, id_to_a, 0);
     obj = RVAL2GOBJ(self);
 
@@ -121,10 +121,10 @@ gboolean
 rbgutil_key_equal(VALUE rb_key, const char *key)
 {
     switch (TYPE(rb_key)) {
-      case RUBY_T_STRING:
+      case T_STRING:
         return RVAL2CBOOL(rb_funcall(rb_key, id_equal, 1, rb_str_new_cstr(key)));
         break;
-      case RUBY_T_SYMBOL:
+      case T_SYMBOL:
         return SYM2ID(rb_key) == rb_intern(key);
         break;
       default:
