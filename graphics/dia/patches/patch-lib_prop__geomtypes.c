$NetBSD: patch-lib_prop__geomtypes.c,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/f57ea2685034ddbafc19f35d9b525a12283d7c24 
via Fedora 

--- lib/prop_geomtypes.c.orig	2014-08-24 15:46:01.000000000 +0000
+++ lib/prop_geomtypes.c
@@ -129,9 +129,10 @@ realprop_set_from_offset(RealProperty *p
 }
 
 static int 
-realprop_get_data_size(RealProperty *prop)
+realprop_get_data_size(void)
 {
-  return sizeof (prop->real_data);
+  RealProperty prop;
+  return sizeof (prop.real_data);
 }
 
 static const PropertyOps realprop_ops = {
@@ -242,9 +243,10 @@ lengthprop_set_from_offset(LengthPropert
 }
 
 static int 
-lengthprop_get_data_size(LengthProperty *prop)
+lengthprop_get_data_size(void)
 {
-  return sizeof (prop->length_data);
+  LengthProperty prop;
+  return sizeof (prop.length_data);
 }
 
 static const PropertyOps lengthprop_ops = {
@@ -358,9 +360,10 @@ fontsizeprop_set_from_offset(FontsizePro
 }
 
 static int 
-fontsizeprop_get_data_size(FontsizeProperty *prop)
+fontsizeprop_get_data_size(void)
 {
-  return sizeof (prop->fontsize_data);
+  FontsizeProperty prop;
+  return sizeof (prop.fontsize_data);
 }
 
 static const PropertyOps fontsizeprop_ops = {
