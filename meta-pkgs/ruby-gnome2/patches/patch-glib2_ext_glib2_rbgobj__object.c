$NetBSD: patch-glib2_ext_glib2_rbgobj__object.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- glib2/ext/glib2/rbgobj_object.c.orig	2013-05-08 15:01:55.000000000 +0000
+++ glib2/ext/glib2/rbgobj_object.c
@@ -225,7 +225,7 @@ rg_s_new_bang(int argc, VALUE *argv, VAL
     rb_scan_args(argc, argv, "01", &params_hash);
 
     if (!NIL_P(params_hash))
-        Check_Type(params_hash, RUBY_T_HASH);
+        Check_Type(params_hash, T_HASH);
 
     if (cinfo->klass != self)
         rb_raise(rb_eTypeError, "%s isn't registered class",
@@ -635,7 +635,7 @@ rg_initialize(int argc, VALUE *argv, VAL
     rb_scan_args(argc, argv, "01", &params_hash);
 
     if (!NIL_P(params_hash))
-        Check_Type(params_hash, RUBY_T_HASH);
+        Check_Type(params_hash, T_HASH);
 
     gobj = rbgobj_gobject_new(RVAL2GTYPE(self), params_hash);
 
