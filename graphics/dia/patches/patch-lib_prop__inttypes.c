$NetBSD: patch-lib_prop__inttypes.c,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/f57ea2685034ddbafc19f35d9b525a12283d7c24 
via Fedora 

--- lib/prop_inttypes.c.orig	2014-08-24 15:46:01.000000000 +0000
+++ lib/prop_inttypes.c
@@ -122,9 +122,10 @@ charprop_set_from_offset(CharProperty *p
 }
 
 static int 
-charprop_get_data_size(CharProperty *prop)
+charprop_get_data_size(void)
 {
-  return sizeof (prop->char_data);
+  CharProperty prop;
+  return sizeof (prop.char_data);
 }
 
 
@@ -229,9 +230,10 @@ boolprop_set_from_offset(BoolProperty *p
 }
 
 static int 
-boolprop_get_data_size(BoolProperty *prop)
+boolprop_get_data_size(void)
 {
-  return sizeof (prop->bool_data);
+  BoolProperty prop;
+  return sizeof (prop.bool_data);
 }
 
 
@@ -339,9 +341,10 @@ intprop_set_from_offset(IntProperty *pro
 }
 
 static int 
-intprop_get_data_size(IntProperty *prop)
+intprop_get_data_size(void)
 {
-  return sizeof (prop->int_data);
+  IntProperty prop;
+  return sizeof (prop.int_data);
 }
 
 static const PropertyOps intprop_ops = {
