$NetBSD: patch-libvaladoc_charts_chart.vala,v 1.1 2026/03/15 19:04:26 wiz Exp $

graphviz 13 compatibility.
https://gitlab.gnome.org/GNOME/vala/-/issues/1621

--- libvaladoc/charts/chart.vala.orig	2026-03-15 19:00:58.898336564 +0000
+++ libvaladoc/charts/chart.vala
@@ -52,15 +52,16 @@ public class Valadoc.Charts.Chart : Api.Visitor {
 		context.render (graph, file_type, file);
 	}
 
-	public uint8[]? write_buffer (string file_type) {
+	public uint8[:size_t]? write_buffer (string file_type) {
 		if (context == null) {
 			context = factory.create_context (graph);
 		}
 
-		uint8[]? data;
+		uint8[:size_t]? data;
 
 		/* This will return null in data if it fails. */
 		context.render_data (graph, file_type, out data);
+
 		return data;
 	}
 
