$NetBSD: patch-src_hb-raster-svg-base.hh,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-raster-svg-base.hh.orig	2026-03-09 18:01:41.975035791 +0000
+++ src/hb-raster-svg-base.hh
@@ -92,7 +92,7 @@ struct hb_svg_str_t
     memcpy (buf, data, n);
     buf[n] = '\0';
     float v = strtof (buf, nullptr);
-    return isfinite (v) ? v : 0.f;
+    return std::isfinite (v) ? v : 0.f;
   }
 
   hb_svg_str_t trim_left () const
