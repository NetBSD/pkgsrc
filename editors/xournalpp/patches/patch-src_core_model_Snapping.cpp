$NetBSD: patch-src_core_model_Snapping.cpp,v 1.1 2024/12/18 12:13:44 nia Exp $

Fix ambiguous reference to sqrt(int).

--- src/core/model/Snapping.cpp.orig	2024-12-18 12:12:44.763157366 +0000
+++ src/core/model/Snapping.cpp
@@ -21,7 +21,7 @@ double snapHorizontally(double x, double
 }
 
 Point snapToGrid(Point const& pos, double gridSize, double tolerance) {
-    double abs_tolerance = (gridSize / sqrt(2)) * tolerance;
+    double abs_tolerance = (gridSize / sqrt(2.0)) * tolerance;
     Point ret{roundToMultiple(pos.x, gridSize), roundToMultiple(pos.y, gridSize), pos.z};
     return distance(ret, pos) < abs_tolerance ? ret : pos;
 }
