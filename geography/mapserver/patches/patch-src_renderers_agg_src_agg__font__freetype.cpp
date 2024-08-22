$NetBSD: patch-src_renderers_agg_src_agg__font__freetype.cpp,v 1.1 2024/08/22 16:16:30 gdt Exp $

Cope with API breakage in FreeType 2.13.3.

https://github.com/MapServer/MapServer/issues/7142

--- src/renderers/agg/src/agg_font_freetype.cpp.orig	2024-08-22 15:18:29.469633241 +0000
+++ src/renderers/agg/src/agg_font_freetype.cpp
@@ -154,10 +154,10 @@ namespace mapserver
 
         FT_Vector*  point;
         FT_Vector*  limit;
-        char*       tags;
+        unsigned char* tags;
 
         int   n;         // index of contour in outline
-        int   first;     // index of first point in contour
+        unsigned   first;     // index of first point in contour
         char  tag;       // current point's state
 
         first = 0;
