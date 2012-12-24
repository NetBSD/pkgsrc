$NetBSD: patch-renderers_agg_include_agg__scanline__u.h,v 1.1 2012/12/24 21:09:47 joerg Exp $

--- renderers/agg/include/agg_scanline_u.h.orig	2012-12-23 17:09:02.000000000 +0000
+++ renderers/agg/include/agg_scanline_u.h
@@ -458,7 +458,7 @@ namespace mapserver
     class scanline32_u8_am : public scanline32_u8
     {
     public:
-        typedef scanline_u8           base_type;
+        typedef scanline32_u8         base_type;
         typedef AlphaMask             alpha_mask_type;
         typedef base_type::cover_type cover_type;
         typedef base_type::coord_type coord_type;
