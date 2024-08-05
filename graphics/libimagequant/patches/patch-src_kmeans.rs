$NetBSD: patch-src_kmeans.rs,v 1.1 2024/08/05 08:30:31 ryoon Exp $

* Revert partially to fix "error[E0277]: `&Box<[HistItem]>` is not an iterator"
  https://github.com/ImageOptim/libimagequant/commit/d6514e825ed1a9c53513d60ee1db989f5d1ea8ff

--- ../src/kmeans.rs.orig	2024-08-05 08:21:27.147848706 +0000
+++ ../src/kmeans.rs
@@ -133,7 +133,7 @@ fn replace_unused_colors(palette: &mut P
             let colors = palette.as_slice();
             // the search is just for diff, ignoring adjusted_weight,
             // because the palette already optimizes for the max weight, so it'd likely find another redundant entry.
-            for item in &hist.items {
+            for item in hist.items.iter() {
                 // the early reject avoids running full palette search for every entry
                 let may_be_worst = colors.get(item.likely_palette_index() as usize)
                     .map_or(true, |pal| pal.diff(&item.color) > worst_diff);
