$NetBSD: patch-libray_libtext_texture.c,v 1.1 2012/12/25 21:08:40 joerg Exp $

--- libray/libtext/texture.c.orig	2012-12-25 18:58:09.000000000 +0000
+++ libray/libtext/texture.c
@@ -121,11 +121,7 @@ Trans *p2model, *world2model;
 /*
  * Compute UV at 'pos' on given primitive.
  */
-TextToUV(mapping, prim, pos, norm, u, v, dpdu, dpdv)
-Mapping *mapping;
-Geom *prim;
-Vector *pos, *norm, *dpdu, *dpdv;
-Float *u, *v;
+void TextToUV(Mapping *mapping, Geom *prim, Vector *pos, Vector *norm, Float *u, Float *v, Vector *dpdu, Vector *dpdv)
 {
 	Vec2d uv;
 	Vector ptmp;
