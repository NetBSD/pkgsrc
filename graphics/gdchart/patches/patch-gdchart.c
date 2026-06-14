$NetBSD: patch-gdchart.c,v 1.3 2026/06/14 15:56:38 nia Exp $

Fix implicit declaration of get_uniq_color.

--- gdchart.c.orig	2004-12-17 18:12:41.000000000 +0000
+++ gdchart.c
@@ -20,6 +20,8 @@
 #define LOWSET		1
 #define CLOSESET	2
 
+long get_uniq_color(gdImagePtr);
+
 /* scaled translation onto graph */
 #define PX( x )		(int)( xorig + (setno*xdepth_3D) + (x)*xscl )
 #define PY( y )		(int)( yorig - (setno*ydepth_3D) + (y)*yscl )
