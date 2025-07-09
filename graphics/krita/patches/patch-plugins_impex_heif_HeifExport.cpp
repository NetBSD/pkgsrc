$NetBSD: patch-plugins_impex_heif_HeifExport.cpp,v 1.1 2025/07/09 19:00:44 wiz Exp $

Compatibility with libheif 1.20.

--- plugins/impex/heif/HeifExport.cpp.orig	2025-07-09 18:49:36.283731814 +0000
+++ plugins/impex/heif/HeifExport.cpp
@@ -250,10 +250,10 @@ KisImportExportErrorCode HeifExport::con
                 img.add_plane(heif_channel_G, width,height, 8);
                 img.add_plane(heif_channel_B, width,height, 8);
 
-                int strideR = 0;
-                int strideG = 0;
-                int strideB = 0;
-                int strideA = 0;
+                size_t strideR = 0;
+                size_t strideG = 0;
+                size_t strideB = 0;
+                size_t strideA = 0;
 
                 uint8_t *ptrR = img.get_plane(heif_channel_R, &strideR);
                 uint8_t *ptrG = img.get_plane(heif_channel_G, &strideG);
@@ -289,7 +289,7 @@ KisImportExportErrorCode HeifExport::con
                 img.create(width, height, heif_colorspace_RGB, chroma);
                 img.add_plane(heif_channel_interleaved, width, height, 12);
 
-                int stride = 0;
+                size_t stride = 0;
 
                 uint8_t *ptr = img.get_plane(heif_channel_interleaved, &stride);
 
@@ -330,8 +330,8 @@ KisImportExportErrorCode HeifExport::con
 
                 img.add_plane(heif_channel_Y, width, height, 8);
 
-                int strideG = 0;
-                int strideA = 0;
+                size_t strideG = 0;
+                size_t strideA = 0;
 
                 uint8_t *ptrG = img.get_plane(heif_channel_Y, &strideG);
                 uint8_t *ptrA = [&]() -> uint8_t * {
@@ -363,8 +363,8 @@ KisImportExportErrorCode HeifExport::con
 
                 img.add_plane(heif_channel_Y, width, height, 12);
 
-                int strideG = 0;
-                int strideA = 0;
+                size_t strideG = 0;
+                size_t strideA = 0;
 
                 uint8_t *ptrG = img.get_plane(heif_channel_Y, &strideG);
                 uint8_t *ptrA = [&]() -> uint8_t * {
