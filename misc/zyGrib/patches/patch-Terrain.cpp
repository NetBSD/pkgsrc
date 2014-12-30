$NetBSD: patch-Terrain.cpp,v 1.3 2014/12/30 08:50:55 plunky Exp $

--- Terrain.cpp.orig	2014-11-02 00:01:52.000000000 +0000
+++ Terrain.cpp
@@ -1109,7 +1109,7 @@ void Terrain::paintEvent(QPaintEvent *)
             
             if (showOrthodromie)
             {
-                QPen penLine(QColor(Qt::white));
+                QPen penLine = QColor(Qt::white);
                 penLine.setWidthF(1.6);
                 pnt.setPen(penLine);
                 draw_Orthodromie(pnt);
