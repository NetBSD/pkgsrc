$NetBSD: patch-libheif_context.cc,v 1.1 2024/11/07 18:42:14 wiz Exp $

https://github.com/strukturag/libheif/commit/3dd7019ff579c038cba96353390cd41edfda927e

--- libheif/context.cc.orig	2024-11-06 16:43:03.000000000 +0000
+++ libheif/context.cc
@@ -1162,7 +1162,7 @@ Result<std::shared_ptr<ImageItem>> HeifC
   heif_encoding_options options = in_options;
 
   if (const auto* nclx = output_image_item->get_forced_output_nclx()) {
-    options.output_nclx_profile = nclx;
+    options.output_nclx_profile = const_cast<heif_color_profile_nclx*>(nclx);
   }
 
   Result<std::shared_ptr<HeifPixelImage>> srcImageResult = output_image_item->convert_colorspace_for_encoding(pixel_image,
