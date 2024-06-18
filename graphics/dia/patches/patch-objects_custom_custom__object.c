$NetBSD: patch-objects_custom_custom__object.c,v 1.1 2024/06/18 09:07:25 markd Exp $

Backport from https://gitlab.gnome.org/GNOME/dia/-/commit/f57ea2685034ddbafc19f35d9b525a12283d7c24 
via Fedora 

--- objects/custom/custom_object.c.orig	2014-08-24 15:46:01.000000000 +0000
+++ objects/custom/custom_object.c
@@ -372,14 +372,7 @@ void custom_setup_properties (ShapeInfo
       info->prop_offsets[i].name = info->props[i].name;
       info->prop_offsets[i].type = info->props[i].type;
       info->prop_offsets[i].offset = offs;
-      /* FIXME:
-	 custom_object.c:328: warning: passing arg 1 of pointer to function 
-	 from incompatible pointer type
-	 We don't have a Property* here so there is not much we can do about.
-	 Maybe it even works cause the sizeof() in *_get_data_size can be
-	 calculated at compile time. Anyway, a mess ;) --hb
-      */
-      size = info->props[i].ops->get_data_size (&info->props[i]);
+      size = info->props[i].ops->get_data_size ();
       info->ext_attr_size += size;
       offs += size;
     }
