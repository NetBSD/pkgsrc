$NetBSD: patch-GLwDrawAP.h,v 1.1 2022/12/21 17:26:55 vins Exp $

Use newly introduced GLAPIVAR for variables.

--- GLwDrawAP.h.orig	2012-05-17 13:55:42.000000000 +0000
+++ GLwDrawAP.h
@@ -59,7 +59,7 @@ typedef struct _GLwMDrawingAreaClassRec 
   } GLwMDrawingAreaClassRec;
 
 
-GLAPI GLwMDrawingAreaClassRec glwMDrawingAreaClassRec;
+GLAPIVAR GLwMDrawingAreaClassRec glwMDrawingAreaClassRec;
 
 
 /* XT */
@@ -70,7 +70,7 @@ typedef struct _GLwDrawingAreaClassRec {
   GLwDrawingAreaClassPart     glwDrawingArea_class;
   } GLwDrawingAreaClassRec;
 
-GLAPI GLwDrawingAreaClassRec glwDrawingAreaClassRec;
+GLAPIVAR GLwDrawingAreaClassRec glwDrawingAreaClassRec;
 
 
 #endif 
