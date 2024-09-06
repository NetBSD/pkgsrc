$NetBSD: patch-src_agg_src_agg__font__freetype.cpp,v 1.1 2024/09/06 09:08:04 wiz Exp $

Adapt for latest freetype2.

--- src/agg/src/agg_font_freetype.cpp.orig	2024-09-06 09:05:11.487799034 +0000
+++ src/agg/src/agg_font_freetype.cpp
@@ -179,7 +179,7 @@ namespace agg
             v_control = v_start;
 
             point = outline.points + first;
-            tags  = outline.tags  + first;
+            tags  = (char*)(outline.tags  + first);
             tag   = FT_CURVE_TAG(tags[0]);
 
             // A contour cannot start with a cubic control point!
