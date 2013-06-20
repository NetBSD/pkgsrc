$NetBSD: patch-glib2_ext_glib2_rbglib.c,v 1.1 2013/06/20 17:16:06 taca Exp $

Ruby 1.8 compatibility.

--- glib2/ext/glib2/rbglib.c.orig	2013-05-08 15:01:55.000000000 +0000
+++ glib2/ext/glib2/rbglib.c
@@ -828,13 +828,13 @@ rbg_inspect (VALUE object)
 VALUE
 rbg_to_array (VALUE object)
 {
-    return rb_convert_type(object, RUBY_T_ARRAY, "Array", "to_ary");
+    return rb_convert_type(object, T_ARRAY, "Array", "to_ary");
 }
 
 VALUE
 rbg_to_hash (VALUE object)
 {
-    return rb_convert_type(object, RUBY_T_HASH, "Hash", "to_hash");
+    return rb_convert_type(object, T_HASH, "Hash", "to_hash");
 }
 
 VALUE
@@ -843,7 +843,7 @@ rbg_check_array_type (VALUE object)
 #ifdef HAVE_RB_CHECK_ARRAY_TYPE
     return rb_check_array_type(object);
 #else
-    return rb_check_convert_type(object, RUBY_T_ARRAY, "Array", "to_ary");
+    return rb_check_convert_type(object, T_ARRAY, "Array", "to_ary");
 #endif
 }
 
@@ -853,7 +853,7 @@ rbg_check_hash_type (VALUE object)
 #ifdef HAVE_RB_CHECK_HASH_TYPE
     return rb_check_hash_type(object);
 #else
-    return rb_check_convert_type(object, RUBY_T_HASH, "Hash", "to_hash");
+    return rb_check_convert_type(object, T_HASH, "Hash", "to_hash");
 #endif
 }
 
