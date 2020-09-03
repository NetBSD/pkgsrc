$NetBSD: patch-libheif_heif__encoder__aom.cc,v 1.1 2020/09/03 19:07:19 otis Exp $

Initialize variable to silence -Werror

--- libheif/heif_encoder_aom.cc.orig	2020-08-26 13:47:18.000000000 +0000
+++ libheif/heif_encoder_aom.cc
@@ -510,7 +510,7 @@ struct heif_error aom_encode_image(void*
 
   aom_image_t input_image;
 
-  aom_img_fmt_t img_format;
+  aom_img_fmt_t img_format = AOM_IMG_FMT_NONE;
 
   switch (chroma) {
     case heif_chroma_420:
