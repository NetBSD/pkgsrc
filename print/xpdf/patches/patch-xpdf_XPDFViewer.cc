$NetBSD: patch-xpdf_XPDFViewer.cc,v 1.1 2012/03/21 17:05:58 hans Exp $

--- xpdf/XPDFViewer.cc.orig	2011-08-15 23:08:53.000000000 +0200
+++ xpdf/XPDFViewer.cc	2012-03-21 17:58:15.368920809 +0100
@@ -134,7 +134,7 @@
 //------------------------------------------------------------------------
 
 struct ZoomMenuInfo {
-  const char *label;
+  char *label;
   double zoom;
 };
 
