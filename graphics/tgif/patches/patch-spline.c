$NetBSD: patch-spline.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- spline.c.orig	2011-05-16 16:21:59.000000000 +0000
+++ spline.c
@@ -808,7 +808,7 @@ typedef struct MultiSplineRec {
 } *MultiSplineRecPtr;
 
 XPoint *MakeMultiSplinePolyVertex(Curved, N, Smooth, XOff, YOff, NumVs, Vs)
-   int *N, XOff, YOff, NumVs;
+   int Curved, *N, XOff, YOff, NumVs;
    char *Smooth;
    IntPoint *Vs;
 {
