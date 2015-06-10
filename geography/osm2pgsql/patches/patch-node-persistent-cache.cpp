$NetBSD: patch-node-persistent-cache.cpp,v 1.1 2015/06/10 01:48:49 wiedi Exp $

Use std namespace to find isnan

--- node-persistent-cache.cpp.orig	2015-04-30 04:15:07.000000000 +0000
+++ node-persistent-cache.cpp
@@ -450,7 +450,7 @@ int node_persistent_cache::set_append(os
         block_id = load_block(block_offset);
 
 #ifdef FIXED_POINT
-    if (isnan(lat) && isnan(lon))
+    if (std::isnan(lat) && std::isnan(lon))
     {
         readNodeBlockCache[block_id].nodes[id & READ_NODE_BLOCK_MASK].lat =
                 INT_MIN;
@@ -512,8 +512,8 @@ int node_persistent_cache::get(struct os
         return 0;
     }
 #else
-    if ((isnan(readNodeBlockCache[block_id].nodes[id & READ_NODE_BLOCK_MASK].lat)) &&
-            (isnan(readNodeBlockCache[block_id].nodes[id & READ_NODE_BLOCK_MASK].lon)))
+    if ((std::isnan(readNodeBlockCache[block_id].nodes[id & READ_NODE_BLOCK_MASK].lat)) &&
+            (std::isnan(readNodeBlockCache[block_id].nodes[id & READ_NODE_BLOCK_MASK].lon)))
     {
         return 1;
     }
@@ -547,7 +547,7 @@ int node_persistent_cache::get_list(node
 
     size_t wrtidx = 0;
     for (size_t i = 0; i < nds.size(); i++) {
-        if (isnan(out[i].lat) && isnan(out[i].lon)) {
+        if (std::isnan(out[i].lat) && std::isnan(out[i].lon)) {
             if (get(&(out[wrtidx]), nds[i]) == 0)
                 wrtidx++;
         } else {
