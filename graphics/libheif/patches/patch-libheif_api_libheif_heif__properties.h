$NetBSD: patch-libheif_api_libheif_heif__properties.h,v 1.1 2026/05/25 03:32:43 wiz Exp $

heif_properties.h: fix "bad_pixels" type
https://github.com/strukturag/libheif/commit/ef124f9988e57a06ad6d102c236d2bb4b82aef5d

--- libheif/api/libheif/heif_properties.h.orig	2026-05-19 18:01:13.000000000 +0000
+++ libheif/api/libheif/heif_properties.h
@@ -335,7 +335,7 @@ heif_error heif_image_add_sensor_bad_pixels_map(heif_i
                                                  uint32_t num_bad_columns,
                                                  const uint32_t* bad_columns,
                                                  uint32_t num_bad_pixels,
-                                                 const heif_bad_pixel* bad_pixels);
+                                                 const struct heif_bad_pixel* bad_pixels);
 
 // Returns the number of sensor bad pixels maps on this image (0 if none).
 LIBHEIF_API
