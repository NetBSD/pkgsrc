$NetBSD: patch-vp8_encoder_onyx__if.c,v 1.1 2023/09/29 09:43:15 wiz Exp $

https://github.com/webmproject/libvpx/commit/3fbd1dca6a4d2dad332a2110d646e4ffef36d590

--- vp8/encoder/onyx_if.c.orig	2023-02-08 01:33:51.000000000 +0000
+++ vp8/encoder/onyx_if.c
@@ -1443,6 +1443,11 @@ void vp8_change_config(VP8_COMP *cpi, VP
   last_h = cpi->oxcf.Height;
   prev_number_of_layers = cpi->oxcf.number_of_layers;
 
+  if (cpi->initial_width) {
+    // TODO(https://crbug.com/1486441): Allow changing thread counts; the
+    // allocation is done once in vp8_create_compressor().
+    oxcf->multi_threaded = cpi->oxcf.multi_threaded;
+  }
   cpi->oxcf = *oxcf;
 
   switch (cpi->oxcf.Mode) {
