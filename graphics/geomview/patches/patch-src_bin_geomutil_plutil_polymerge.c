$NetBSD: patch-src_bin_geomutil_plutil_polymerge.c,v 1.1 2013/03/02 18:09:30 joerg Exp $

--- src/bin/geomutil/plutil/polymerge.c.orig	2013-03-01 21:44:20.000000000 +0000
+++ src/bin/geomutil/plutil/polymerge.c
@@ -73,6 +73,9 @@ typedef struct point {
 	float x, y, z, w;
 } P;
 
+static void deface(F *f);
+static void normal_ize(F *f);
+static void femerge(Fe *fe1, Fe *fe2);
 
 struct vertex {
 	P p;
@@ -617,8 +620,7 @@ unfedge(fe)
  * Merge two faces
  * We delete these face-edges from both faces
  */
-femerge(fe1, fe2)
-    register Fe *fe1, *fe2;
+static void femerge(Fe *fe1, Fe *fe2)
 {
     F *f1, *f2;
     register Fe *tfe;
@@ -681,8 +683,7 @@ femerge(fe1, fe2)
 
 #define PRETTY(x)  ((int)(x) - 0x10000000)
 
-fecheck(fe)
-    Fe *fe;
+static void fecheck(Fe *fe)
 {
     register Fe *fee;
     int ne;
@@ -739,8 +740,7 @@ echeck(v0, v1)
 
 
 
-normal_ize(f)
-   F *f;
+static void normal_ize(F *f)
 {
     register Fe *fe;
 
@@ -801,8 +801,7 @@ normal_ize(f)
 /*
  * Delete a face, erasing all edges.
  */
-deface(f)
-    F *f;
+static void deface(F *f)
 {
     register Fe *fe, *fee;
 
@@ -913,7 +912,7 @@ and faceno is the integer index of the f
 /* Generate 3x3 rotation matrix which takes va -> vb
  * Assumes va and vb both unit vectors.
  */
-rotation(P *va, P *vb, float T[3][3])
+static void rotation(P *va, P *vb, float T[3][3])
 {
     float adotb = VDOT(va, vb);
     float ab_1 = adotb - 1;
