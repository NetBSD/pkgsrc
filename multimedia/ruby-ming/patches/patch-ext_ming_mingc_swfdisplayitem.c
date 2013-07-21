$NetBSD: patch-ext_ming_mingc_swfdisplayitem.c,v 1.1 2013/07/21 02:48:12 taca Exp $

* Don't depend on parenthesis by CPP macro.

--- ext/ming/mingc/swfdisplayitem.c.orig	2008-07-05 21:04:39.000000000 +0000
+++ ext/ming/mingc/swfdisplayitem.c
@@ -386,7 +386,7 @@ rb_SWFDisplayItem_set_color_add(argc, ar
 
   rb_scan_args(argc, argv, "31", &r, &g, &b, &a);
   Data_Get_Struct(self, struct RSWFDisplayItem, i);
-  if NIL_P(a)
+  if (NIL_P(a))
     alpha = 0;
   else
     alpha = NUM2INT(a);
@@ -407,7 +407,7 @@ rb_SWFDisplayItem_set_color_mult(argc, a
 
   rb_scan_args(argc, argv, "31", &r, &g, &b, &a);
   Data_Get_Struct(self, struct RSWFDisplayItem, i);
-  if NIL_P(a)
+  if (NIL_P(a))
     alpha = 1.0;
   else
     alpha = NUM2DBL(a);
