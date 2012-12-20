$NetBSD: patch-xquery.c,v 1.1 2012/12/20 22:04:14 joerg Exp $

--- xquery.c.orig	2012-12-20 17:54:14.000000000 +0000
+++ xquery.c
@@ -670,10 +670,7 @@ int button;
     return ms_Query;
 }
 
-int query_motion(py, xpos, ypos, button)
-struct player *py;
-int xpos, ypos;
-int button;
+void query_motion(struct player *py, int xpos, int ypos, int button)
 {
     int hitrow;
     int qtype = py->answers[py->query_hit].query->qtype;
