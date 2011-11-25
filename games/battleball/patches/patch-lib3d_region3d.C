$NetBSD: patch-lib3d_region3d.C,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/region3d.C.orig	2011-11-25 15:16:05.000000000 +0000
+++ lib3d/region3d.C
@@ -44,7 +44,7 @@ region3d::region3d(const panelList& othe
   if (wantEdges)
     for(p= otherPanels.begin(); p != otherPanels.end(); p++)
       edges.AddPanel(*p);
-  box.MakeBoundingBox(pts.table(),farthestDist);
+  box.MakeBoundingBox(pts.my_table(),farthestDist);
 }
 
 
@@ -83,7 +83,7 @@ bool region3d::InFrustum(const pt3d& vie
 int region3d::Add(const xpanel3d& p) {
 if (p.ptNums.Num() >0) {
     edges.AddPanel(p);
-    box.MakeBoundingBox(pts.table(), farthestDist);
+    box.MakeBoundingBox(pts.my_table(), farthestDist);
     return panels.Add(p);
   }
   else
@@ -123,7 +123,7 @@ void region3d::InitPanelsEtc(int *srcPan
     //panels[panels.Num()-1].normal *= normalDir;
     edges.AddPanel(panels[panels.Num()-1]);
   }
-  box.MakeBoundingBox(pts.table(),farthestDist);
+  box.MakeBoundingBox(pts.my_table(),farthestDist);
 }
 
 
