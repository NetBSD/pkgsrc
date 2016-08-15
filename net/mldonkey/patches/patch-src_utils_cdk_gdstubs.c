$NetBSD: patch-src_utils_cdk_gdstubs.c,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/utils/cdk/gdstubs.c.orig	2012-06-24 07:59:41.000000000 +0000
+++ src/utils/cdk/gdstubs.c
@@ -489,7 +489,7 @@ int ml_image_pngversion(void)
   CAMLlocal1 (v);
 #ifdef HAVE_PNGVERSION
   #include <png.h>
-  v = copy_int32 ((int32)png_access_version_number());
+  v = copy_int32 ((int32_t)png_access_version_number());
   CAMLreturn (v);
 #else
   raise_constant(*(value *)caml_named_value("gd type not supported"));
