$NetBSD: patch-src_quant.rs,v 1.1 2024/08/05 08:30:31 ryoon Exp $

* Revert partially to fix "error[E0277]: `&Box<[HistItem]>` is not an iterator"
  https://github.com/ImageOptim/libimagequant/commit/d6514e825ed1a9c53513d60ee1db989f5d1ea8ff

--- ../src/quant.rs.orig	2024-08-05 08:22:20.583105566 +0000
+++ ../src/quant.rs
@@ -441,7 +441,7 @@ fn refine_palette(palette: &mut PalF, at
 #[cold]
 fn palette_from_histogram(hist: &HistogramInternal, max_colors: PalLen) -> (PalF, Option<f64>) {
     let mut hist_pal = PalF::new();
-    for item in &hist.items {
+    for item in hist.items.iter() {
         hist_pal.push(item.color, PalPop::new(item.perceptual_weight));
     }
 
