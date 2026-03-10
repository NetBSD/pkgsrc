$NetBSD: patch-src_hb-raster-svg-parse.hh,v 1.1 2026/03/10 05:58:05 wiz Exp $

error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?
https://github.com/harfbuzz/harfbuzz/issues/5806

--- src/hb-raster-svg-parse.hh.orig	2026-03-09 18:01:56.805896259 +0000
+++ src/hb-raster-svg-parse.hh
@@ -320,7 +320,7 @@ struct hb_svg_float_parser_t
     }
     buf[n] = '\0';
     float v = strtof (buf, nullptr);
-    return isfinite (v) ? v : 0.f;
+    return std::isfinite (v) ? v : 0.f;
   }
 
   bool next_flag ()
