$NetBSD: patch-GLwDrawA.h,v 1.1 2022/12/21 17:26:55 vins Exp $

Fix NULL variable definition.

--- GLwDrawA.h.orig	2012-05-17 13:55:42.000000000 +0000
+++ GLwDrawA.h
@@ -131,12 +131,18 @@
 #define GLwNaccumAlphaSize	"accumAlphaSize"
 #define GLwCAccumAlphaSize	"AccumAlphaSize"
 
+#if (defined(__GNUC__) && __GNUC__ >= 4) || (defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590))
+#  define GLAPIVAR extern __attribute__((visibility("default")))
+#else
+#  define GLAPIVAR extern
+#endif
+
 #ifdef __GLX_MOTIF
 
 typedef struct _GLwMDrawingAreaClassRec	*GLwMDrawingAreaWidgetClass;
 typedef struct _GLwMDrawingAreaRec	*GLwMDrawingAreaWidget;
 
-GLAPI WidgetClass glwMDrawingAreaWidgetClass;
+GLAPIVAR WidgetClass glwMDrawingAreaWidgetClass;
 
 
 #else 
@@ -144,7 +150,7 @@ GLAPI WidgetClass glwMDrawingAreaWidgetC
 typedef struct _GLwDrawingAreaClassRec	*GLwDrawingAreaWidgetClass;
 typedef struct _GLwDrawingAreaRec	*GLwDrawingAreaWidget;
 
-GLAPI WidgetClass glwDrawingAreaWidgetClass;
+GLAPIVAR WidgetClass glwDrawingAreaWidgetClass;
 
 
 #endif
