$NetBSD: patch-png2-xvmisc.c,v 1.1 1999/11/14 13:26:01 rh Exp $

--- xvmisc.c.orig	Sun Nov 14 14:05:45 1999
+++ xvmisc.c	Sun Nov 14 14:05:49 1999
@@ -522,6 +522,10 @@
 
     if (pcdW) XDestroyWindow(theDisp, pcdW);
 
+#ifdef HAVE_PNG
+    if (pngW)  XDestroyWindow(theDisp, pngW);
+#endif
+
     /* if NOT using stdcmap for images, free stdcmap */
     if (colorMapMode != CM_STDCMAP) { 
       int j;
@@ -717,6 +721,10 @@
   
 #ifdef HAVE_TIFF
   if (tiffW) XDefineCursor(theDisp, tiffW, otherc);
+#endif
+
+#ifdef HAVE_PNG
+  if (pngW)  XDefineCursor(theDisp, pngW, otherc);
 #endif
   
   if (pcdW) XDefineCursor(theDisp, pcdW, otherc);
