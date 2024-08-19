$NetBSD: patch-engines_ags_lib_freetype-2.1.3_autohint_ahglyph.cpp,v 1.1 2024/08/19 20:54:07 wiz Exp $

AGS: Support for FreeType 2.13.3 changes to FT_Outline struct

https://github.com/scummvm/scummvm/commit/65977961b20ba97b1213b5267da0cb1efb49063b

--- engines/ags/lib/freetype-2.1.3/autohint/ahglyph.cpp.orig	2024-03-15 22:57:03.000000000 +0000
+++ engines/ags/lib/freetype-2.1.3/autohint/ahglyph.cpp
@@ -296,7 +296,11 @@ void ah_outline_save(AH_Outline outline,
 	AH_Point point = outline->points;
 	AH_Point point_limit = point + outline->num_points;
 	FT_Vector *vec = gloader->current.outline.points;
+#if (FREETYPE_MAJOR * 1000 + FREETYPE_MINOR) * 1000 + FREETYPE_PATCH < 2013003
 	char *tag = gloader->current.outline.tags;
+#else
+	unsigned char *tag = gloader->current.outline.tags;
+#endif
 
 	/* we assume that the glyph loader has already been checked for storage */
 	for (; point < point_limit; point++, vec++, tag++) {
@@ -408,8 +412,11 @@ FT_Error ah_outline_load(AH_Outline outl
 
 		/* compute Bezier flags */
 		{
+#if (FREETYPE_MAJOR * 1000 + FREETYPE_MINOR) * 1000 + FREETYPE_PATCH < 2013003
 			char *tag = source->tags;
-
+#else
+			unsigned char *tag = source->tags;
+#endif
 			for (point = points; point < point_limit; point++, tag++) {
 				switch (FT_CURVE_TAG(*tag)) {
 				case FT_CURVE_TAG_CONIC:
@@ -457,12 +464,17 @@ FT_Error ah_outline_load(AH_Outline outl
 		{
 			AH_Point *contour = outline->contours;
 			AH_Point *contour_limit = contour + outline->num_contours;
+#if (FREETYPE_MAJOR * 1000 + FREETYPE_MINOR) * 1000 + FREETYPE_PATCH < 2013003
 			short *end = source->contours;
 			short idx = 0;
+#else
+			unsigned short *end = source->contours;
+			unsigned short idx = 0;
+#endif
 
 			for (; contour < contour_limit; contour++, end++) {
 				contour[0] = points + idx;
-				idx = (short)(end[0] + 1);
+				idx = end[0] + 1;
 			}
 		}
 
