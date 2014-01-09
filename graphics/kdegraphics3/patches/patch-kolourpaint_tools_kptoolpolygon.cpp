$NetBSD: patch-kolourpaint_tools_kptoolpolygon.cpp,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- kolourpaint/tools/kptoolpolygon.cpp.orig	2005-09-10 08:19:05.000000000 +0000
+++ kolourpaint/tools/kptoolpolygon.cpp
@@ -560,7 +560,7 @@ void kpToolPolygon::applyModifiers ()
         // diagonal (dist from start maintained)
         else
         {
-            const double dist = sqrt (diffx * diffx + diffy * diffy);
+            const double dist = sqrt ((double)(diffx * diffx + diffy * diffy));
 
             #define sgn(a) ((a)<0?-1:1)
             // Round distances _before_ adding to any coordinate
