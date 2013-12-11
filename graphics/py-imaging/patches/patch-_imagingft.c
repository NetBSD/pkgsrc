$NetBSD: patch-_imagingft.c,v 1.1 2013/12/11 23:55:11 markd Exp $

fix a freetype 2.0 hangover

--- _imagingft.c.orig	2009-11-01 00:44:12.000000000 +0000
+++ _imagingft.c
@@ -70,7 +70,11 @@ struct {
     const char* message;
 } ft_errors[] =
 
+#if defined(USE_FREETYPE_2_1)
+#include FT_ERRORS_H
+#else
 #include <freetype/fterrors.h>
+#endif
 
 /* -------------------------------------------------------------------- */
 /* font objects */
