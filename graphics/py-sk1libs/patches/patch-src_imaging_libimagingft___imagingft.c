$NetBSD: patch-src_imaging_libimagingft___imagingft.c,v 1.1 2014/03/22 15:57:07 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- src/imaging/libimagingft/_imagingft.c.orig	2009-11-01 00:44:12.000000000 +0000
+++ src/imaging/libimagingft/_imagingft.c
@@ -70,7 +70,14 @@ struct {
     const char* message;
 } ft_errors[] =
 
+#if defined(USE_FREETYPE_2_1)
+/* freetype 2.1 and newer */
+#include <ft2build.h>
+#include FT_ERRORS_H
+#else
+/* freetype 2.0 */
 #include <freetype/fterrors.h>
+#endif
 
 /* -------------------------------------------------------------------- */
 /* font objects */
