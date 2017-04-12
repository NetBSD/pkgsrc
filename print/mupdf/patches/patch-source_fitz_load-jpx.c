$NetBSD: patch-source_fitz_load-jpx.c,v 1.5 2017/04/12 13:03:08 leot Exp $

Restrict OPJ_STATIC to Windows (avoid linking errors due to hidden symbols)

--- source/fitz/load-jpx.c.orig	2017-03-31 14:23:45.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -443,7 +443,9 @@ fz_load_jpx_info(fz_context *ctx, unsign
 
 #else /* HAVE_LURATECH */
 
+#if defined(_WIN32) || defined(_WIN64)
 #define OPJ_STATIC
+#endif
 #define OPJ_HAVE_INTTYPES_H
 #if !defined(_WIN32) && !defined(_WIN64)
 #define OPJ_HAVE_STDINT_H
