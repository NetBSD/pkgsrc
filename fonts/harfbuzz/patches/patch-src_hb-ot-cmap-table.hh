$NetBSD: patch-src_hb-ot-cmap-table.hh,v 1.1 2026/01/11 06:00:33 wiz Exp $

[cmap] malloc fail test (#5710)
https://github.com/harfbuzz/harfbuzz/commit/1265ff8d990284f04d8768f35b0e20ae5f60daae

--- src/hb-ot-cmap-table.hh.orig	2025-12-27 20:33:25.000000000 +0000
+++ src/hb-ot-cmap-table.hh
@@ -1670,6 +1670,10 @@ struct SubtableUnicodesCache {
   {
     SubtableUnicodesCache* cache =
         (SubtableUnicodesCache*) hb_malloc (sizeof(SubtableUnicodesCache));
+
+    if (unlikely (!cache))
+      return nullptr;
+
     new (cache) SubtableUnicodesCache (source_table);
     return cache;
   }
