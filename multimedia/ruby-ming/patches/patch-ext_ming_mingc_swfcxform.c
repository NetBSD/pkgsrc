$NetBSD: patch-ext_ming_mingc_swfcxform.c,v 1.1 2013/07/21 02:48:12 taca Exp $

* Don't depend on parenthesis by CPP macro.

--- ext/ming/mingc/swfcxform.c.orig	2008-07-08 16:45:44.000000000 +0000
+++ ext/ming/mingc/swfcxform.c
@@ -66,7 +66,7 @@ rb_SWFCXform_set_color_add(argc, argv, s
 
   rb_scan_args(argc, argv, "31", &r, &g, &b, &a);
   Data_Get_Struct(self, struct RSWFCXform, cx);
-  if NIL_P(a)
+  if (NIL_P(a))
     alpha = 0;
   else
     alpha = NUM2INT(a);
@@ -87,7 +87,7 @@ rb_SWFCXform_set_color_mult(argc, argv, 
 
   rb_scan_args(argc, argv, "31", &r, &g, &b, &a);
   Data_Get_Struct(self, struct RSWFCXform, cx);
-  if NIL_P(a)
+  if (NIL_P(a))
     alpha = 1.0;
   else
     alpha = NUM2DBL(a);
