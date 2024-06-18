$NetBSD: patch-polygon.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- polygon.c.orig	2011-06-09 16:25:07.000000000 +0000
+++ polygon.c
@@ -1020,7 +1020,7 @@ void ContinueForStructSplinePolygonContr
 static
 void EraseStructSplineLinesForContAndUpdateSvs(OrigX, OrigY, grid_x, grid_y,
       pev, num_pts, psv, sn, psv2, sn2, pipt_prev, pipt_first)
-   int OrigX, OrigY, grid_x, grid_y, sn, sn2;
+   int OrigX, OrigY, grid_x, grid_y, num_pts, sn, sn2;
    XEvent *pev;
    XPoint **psv, **psv2;
    IntPointTriplet *pipt_prev, *pipt_first;
