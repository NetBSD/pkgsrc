$NetBSD: patch-lib_prop__text.c,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/f57ea2685034ddbafc19f35d9b525a12283d7c24 
via Fedora 

--- lib/prop_text.c.orig	2014-08-24 15:46:01.000000000 +0000
+++ lib/prop_text.c
@@ -208,9 +208,10 @@ stringprop_set_from_offset(StringPropert
 }
 
 static int 
-stringprop_get_data_size(StringProperty *prop)
+stringprop_get_data_size(void)
 {
-  return sizeof (prop->string_data); /* only the pointer */
+  StringProperty prop;
+  return sizeof (prop.string_data); /* only the pointer */
 }
 
 static StringListProperty *
