$NetBSD: patch-plugins_impex_heif_HeifImport.cpp,v 1.1 2025/07/09 19:00:44 wiz Exp $

Compatibility with libheif 1.20.

--- plugins/impex/heif/HeifImport.cpp.orig	2025-07-09 18:54:00.656835767 +0000
+++ plugins/impex/heif/HeifImport.cpp
@@ -387,8 +387,8 @@ KisImportExportErrorCode HeifImport::con
 
         if (heifChroma == heif_chroma_monochrome) {
             dbgFile << "monochrome heif file, bits:" << luma;
-            int strideG = 0;
-            int strideA = 0;
+            size_t strideG = 0;
+            size_t strideA = 0;
             const uint8_t *imgG = heifimage.get_plane(heif_channel_Y, &strideG);
             const uint8_t *imgA =
                 heifimage.get_plane(heif_channel_Alpha, &strideA);
@@ -409,10 +409,10 @@ KisImportExportErrorCode HeifImport::con
         } else if (heifChroma == heif_chroma_444) {
             dbgFile << "planar heif file, bits:" << luma;
 
-            int strideR = 0;
-            int strideG = 0;
-            int strideB = 0;
-            int strideA = 0;
+            size_t strideR = 0;
+            size_t strideG = 0;
+            size_t strideB = 0;
+            size_t strideA = 0;
             const uint8_t* imgR = heifimage.get_plane(heif_channel_R, &strideR);
             const uint8_t* imgG = heifimage.get_plane(heif_channel_G, &strideG);
             const uint8_t* imgB = heifimage.get_plane(heif_channel_B, &strideB);
@@ -439,7 +439,7 @@ KisImportExportErrorCode HeifImport::con
                                     displayNits,
                                     colorSpace);
         } else if (heifChroma == heif_chroma_interleaved_RGB || heifChroma == heif_chroma_interleaved_RGBA) {
-            int stride = 0;
+            size_t stride = 0;
             dbgFile << "interleaved SDR heif file, bits:" << luma;
 
             const uint8_t *img = heifimage.get_plane(heif_channel_interleaved, &stride);
@@ -461,7 +461,7 @@ KisImportExportErrorCode HeifImport::con
                                       colorSpace);
 
         } else if (heifChroma == heif_chroma_interleaved_RRGGBB_LE || heifChroma == heif_chroma_interleaved_RRGGBBAA_LE || heifChroma == heif_chroma_interleaved_RRGGBB_BE || heifChroma == heif_chroma_interleaved_RRGGBB_BE) {
-            int stride = 0;
+            size_t stride = 0;
             dbgFile << "interleaved HDR heif file, bits:" << luma;
 
             const uint8_t *img =
