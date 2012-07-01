$NetBSD: patch-Terrain.cpp,v 1.2 2012/07/01 07:21:35 plunky Exp $

--- Terrain.cpp.orig	2012-06-03 21:03:41.000000000 +0000
+++ Terrain.cpp
@@ -1032,7 +1032,7 @@ void Terrain::paintEvent(QPaintEvent * /
             
             if (showOrthodromie)
             {
-                QPen penLine(QColor(Qt::white));
+                QPen penLine = QColor(Qt::white);
                 penLine.setWidthF(1.6);
                 pnt.setPen(penLine);
                 draw_Orthodromie(pnt);
