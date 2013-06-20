$NetBSD: patch-glib2_ext_glib2_rbglib__utils.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- glib2/ext/glib2/rbglib_utils.c.orig	2013-05-08 15:01:55.000000000 +0000
+++ glib2/ext/glib2/rbglib_utils.c
@@ -255,7 +255,7 @@ rg_s_parse_debug_string(G_GNUC_UNUSED VA
     VALUE ary;
     GDebugKey* gkeys;
 
-    Check_Type(keys, RUBY_T_HASH);
+    Check_Type(keys, T_HASH);
     ary = rb_funcall(keys, rb_intern("to_a"), 0);
     nkeys = RARRAY_LEN(ary);
     gkeys = ALLOCA_N(GDebugKey, nkeys);
