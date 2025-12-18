$NetBSD: patch-web_showgraph.c,v 1.3 2025/12/18 10:09:22 wiz Exp $

Adapt for recent rrdtool.

--- web/showgraph.c.orig	2025-12-18 09:59:43.766879792 +0000
+++ web/showgraph.c
@@ -1215,7 +1215,7 @@ void generate_graph(char *gdeffn, char *
 	rrd_clear_error();
 
 #ifdef RRDTOOL12
-	result = rrd_graph(rrdargcount, rrdargs, &calcpr, &xsize, &ysize, NULL, &ymin, &ymax);
+	result = rrd_graph(rrdargcount, (const char **)rrdargs, &calcpr, &xsize, &ysize, NULL, &ymin, &ymax);
 
 	/*
 	 * If we have neither the upper- nor lower-limits of the graph, AND we allow vertical 
