$NetBSD: patch-source_blender_editors_transform_transform__convert__graph.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/editors/transform/transform_convert_graph.cc.orig	2026-09-13 15:28:27.686039515 +0000
+++ source/blender/editors/transform/transform_convert_graph.cc
@@ -223,7 +223,7 @@ static float graph_key_shortest_dist(
       graph_bezt_get_transform_selection(t, bezt, use_handle, &sel_left, &sel_key, &sel_right);
 
       if (sel_left || sel_key || sel_right) {
-        dist = std::min({dist, td->dist, fabs(td_iter->center[0] - td->center[0])});
+        dist = std::min({dist, td->dist, std::fabs(td_iter->center[0] - td->center[0])});
       }
 
       td_iter += 3;
