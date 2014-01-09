$NetBSD: patch-kolourpaint_widgets_kpcolorsimilaritycube.cpp,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- kolourpaint/widgets/kpcolorsimilaritycube.cpp.orig	2005-09-10 08:19:05.000000000 +0000
+++ kolourpaint/widgets/kpcolorsimilaritycube.cpp
@@ -45,7 +45,7 @@
 
 
 const double kpColorSimilarityCube::colorCubeDiagonalDistance =
-    sqrt (255 * 255 * 3);
+    sqrt ((double)(255 * 255 * 3));
 
 kpColorSimilarityCube::kpColorSimilarityCube (int look,
                                               kpMainWindow *mainWindow,
