$NetBSD: patch-src_hb-vector-svg-utils.hh,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-vector-svg-utils.hh.orig	2026-03-09 18:02:17.366055055 +0000
+++ src/hb-vector-svg-utils.hh
@@ -80,7 +80,7 @@ hb_svg_append_num (hb_vector_t<char> *buf,
   if (fabsf (v) < rounded_zero_threshold)
     v = 0.f;
 
-  if (!(v == v) || !isfinite (v))
+  if (!(v == v) || !std::isfinite (v))
   {
     hb_svg_append_c (buf, '0');
     return;
