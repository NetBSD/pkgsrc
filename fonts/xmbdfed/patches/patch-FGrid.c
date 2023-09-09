$NetBSD: patch-FGrid.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Callback values already assigned.

--- FGrid.c.orig	2004-02-08 23:58:59.000000000 +0000
+++ FGrid.c
@@ -4267,7 +4267,7 @@ Widget w;
     pi->sel_start = pi->sel_end = cb.start;
     Select(pi->sel_start, pi->selmap);
 
-    _XmuttFGridDrawCells(fw, pi->sel_start, pi->sel_end, True, True);
+    _XmuttFGridDrawCells(fw, cb.start, cb.end, True, True);
 
     /*
      * Call the modified callback.
