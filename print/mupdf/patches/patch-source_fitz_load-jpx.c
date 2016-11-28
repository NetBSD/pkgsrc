$NetBSD: patch-source_fitz_load-jpx.c,v 1.4 2016/11/28 14:40:42 leot Exp $

Restrict OPJ_STATIC to Windows (avoid linking errors due to hidden symbols)

--- source/fitz/load-jpx.c.orig	2016-11-08 19:06:14.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -484,7 +484,9 @@ fz_load_jpx_info(fz_context *ctx, unsign
 /* Without the definition of OPJ_STATIC, compilation fails on windows
  * due to the use of __stdcall. We believe it is required on some
  * linux toolchains too. */
+#ifdef _WIN32
 #define OPJ_STATIC
+#endif
 #ifndef _MSC_VER
 #define OPJ_HAVE_STDINT_H
 #endif
