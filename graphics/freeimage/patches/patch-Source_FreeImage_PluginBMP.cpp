$NetBSD: patch-Source_FreeImage_PluginBMP.cpp,v 1.1 2022/06/26 10:49:54 he Exp $

Apparently noone has built this on big-endian hosts in a while...
Replace bpp (undeclared) with dst_bpp (declared local).

--- Source/FreeImage/PluginBMP.cpp.orig	2016-06-15 10:35:30.000000000 +0000
+++ Source/FreeImage/PluginBMP.cpp
@@ -1419,7 +1419,7 @@ Save(FreeImageIO *io, FIBITMAP *dib, fi_
 
 			free(buffer);
 #ifdef FREEIMAGE_BIGENDIAN
-		} else if (bpp == 16) {
+		} else if (dst_bpp == 16) {
 			int padding = dst_pitch - dst_width * sizeof(WORD);
 			WORD pad = 0;
 			WORD pixel;
@@ -1440,7 +1440,7 @@ Save(FreeImageIO *io, FIBITMAP *dib, fi_
 			}
 #endif
 #if FREEIMAGE_COLORORDER == FREEIMAGE_COLORORDER_RGB
-		} else if (bpp == 24) {
+		} else if (dst_bpp == 24) {
 			int padding = dst_pitch - dst_width * sizeof(FILE_BGR);
 			DWORD pad = 0;
 			FILE_BGR bgr;
@@ -1461,7 +1461,7 @@ Save(FreeImageIO *io, FIBITMAP *dib, fi_
 					}
 				}
 			}
-		} else if (bpp == 32) {
+		} else if (dst_bpp == 32) {
 			FILE_BGRA bgra;
 			for(unsigned y = 0; y < dst_height; y++) {
 				BYTE *line = FreeImage_GetScanLine(dib, y);
