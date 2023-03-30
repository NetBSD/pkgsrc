$NetBSD: patch-libheif_heif__colorconversion.cc,v 1.1 2023/03/30 20:29:48 joerg Exp $

Avoid -Werror=maybe-initialized with GCC 13

--- libheif/heif_colorconversion.cc.orig	2023-03-30 00:33:32.216318787 +0000
+++ libheif/heif_colorconversion.cc
@@ -1866,7 +1866,7 @@ Op_mono_to_RGB24_32::convert_colorspace(
     return nullptr;
   }
 
-  const uint8_t* in_y, * in_a;
+  const uint8_t* in_y, * in_a = nullptr;
   int in_y_stride = 0, in_a_stride;
 
   uint8_t* out_p;
