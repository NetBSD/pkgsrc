$NetBSD: patch-libheif_api_libheif_heif.h,v 1.1 2024/11/07 18:42:14 wiz Exp $

https://github.com/strukturag/libheif/commit/3dd7019ff579c038cba96353390cd41edfda927e

--- libheif/api/libheif/heif.h.orig	2024-11-06 16:43:03.000000000 +0000
+++ libheif/api/libheif/heif.h
@@ -2363,7 +2363,7 @@ struct heif_encoding_options
 
   // Set this to the NCLX parameters to be used in the output image or set to NULL
   // when the same parameters as in the input image should be used.
-  const struct heif_color_profile_nclx* output_nclx_profile;
+  struct heif_color_profile_nclx* output_nclx_profile;
 
   uint8_t macOS_compatibility_workaround_no_nclx_profile;
 
