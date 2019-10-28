$NetBSD: patch-Terrain.cpp,v 1.4 2019/10/28 19:02:35 bouyer Exp $

--- Terrain.cpp.orig	2016-11-09 17:27:38.000000000 +0100
+++ Terrain.cpp	2019-10-28 15:49:41.442663233 +0100
@@ -1135,7 +1135,7 @@
             
             if (showOrthodromie)
             {
-                QPen penLine(Qt::white);
+                QPen penLine = QColor(Qt::white);
                 penLine.setWidthF(1.6);
                 pnt.setPen(penLine);
                 draw_Orthodromie(pnt);
