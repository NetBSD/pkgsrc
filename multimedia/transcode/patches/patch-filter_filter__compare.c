$NetBSD: patch-filter_filter__compare.c,v 1.1 2016/05/16 19:41:17 adam Exp $

Fix for ImageMagick v7.

--- filter/filter_compare.c.orig	2016-05-15 12:50:52.000000000 +0000
+++ filter/filter_compare.c
@@ -24,7 +24,7 @@
 
 /* Note: because of ImageMagick bogosity, this must be included first, so
  * we can undefine the PACKAGE_* symbols it splats into our namespace */
-#include <magick/api.h>
+#include <MagickCore/MagickCore.h>
 #undef PACKAGE_BUGREPORT
 #undef PACKAGE_NAME
 #undef PACKAGE_STRING
@@ -234,7 +234,6 @@ int tc_filter(frame_list_t *ptr_, char *
 					      compare[instance]->width,
 					      compare[instance]->height,
 					      GaussianFilter,
-					      1,
 					      &exception_info);
 			if (verbose > 1)
 				tc_log_info(MOD_NAME, "Flipping the Image");
@@ -257,7 +256,7 @@ int tc_filter(frame_list_t *ptr_, char *
 			for (t = 0; t < pattern->rows; t++)
 				for (r = 0; r < pattern->columns; r++){
 					index = t*pattern->columns + r;
-					if (pixel_packet[index].opacity == 0){
+					if (pixel_packet[index].alpha == 0){
 						temp=tc_malloc(sizeof(struct pixelsMask));
 						temp->row=t;
 						temp->col=r;
