$NetBSD: patch-ft.c,v 1.1 2025/12/21 13:57:33 prlw1 Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- ft.c.orig	2003-12-31 21:30:50.000000000 +0000
+++ ft.c
@@ -12,11 +12,12 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <sys/types.h>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftsnames.h>
-#include <freetype/ttnameid.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_SFNT_NAMES_H
+#include FT_TRUETYPE_IDS_H
+#include FT_OUTLINE_H
 #include "pt1.h"
 #include "global.h"
 
@@ -457,7 +458,11 @@ static double lastx, lasty;
 
 static int
 outl_moveto(
+#if FREETYPE_MAJOR == 2 && FREETYPE_MINOR >= 13
+	const FT_Vector *to,
+#else
 	FT_Vector *to,
+#endif
 	void *unused
 )
 {
@@ -477,7 +482,11 @@ outl_moveto(
 
 static int
 outl_lineto(
+#if FREETYPE_MAJOR == 2 && FREETYPE_MINOR >= 13
+	const FT_Vector *to,
+#else
 	FT_Vector *to,
+#endif
 	void *unused
 )
 {
@@ -493,8 +502,13 @@ outl_lineto(
 
 static int
 outl_conicto(
+#if FREETYPE_MAJOR == 2 && FREETYPE_MINOR >= 13
+	const FT_Vector *control1,
+	const FT_Vector *to,
+#else
 	FT_Vector *control1,
 	FT_Vector *to,
+#endif
 	void *unused
 )
 {
@@ -514,9 +528,15 @@ outl_conicto(
 
 static int
 outl_cubicto(
+#if FREETYPE_MAJOR == 2 && FREETYPE_MINOR >= 13
+	const FT_Vector *control1,
+	const FT_Vector *control2,
+	const FT_Vector *to,
+#else
 	FT_Vector *control1,
 	FT_Vector *control2,
 	FT_Vector *to,
+#endif
 	void *unused
 )
 {
