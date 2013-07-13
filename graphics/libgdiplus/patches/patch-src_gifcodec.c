$NetBSD: patch-src_gifcodec.c,v 1.1 2013/07/13 10:50:05 obache Exp $

* fixes build with giflib>=5

--- src/gifcodec.c.orig	2011-01-13 22:28:19.000000000 +0000
+++ src/gifcodec.c
@@ -39,8 +39,12 @@ GUID gdip_gif_image_format_guid = {0xb96
 
 #include "gifcodec.h"
 
-/* giflib declares this incorrectly as EgifOpen */
+/* giflib declares this incorrectly as EgifOpen up to 4.1.2
+   GIF_LIB_VERSION is defined up to 4.1.6, and prototype is changed in 5.0,
+   so it is safe to use it as check condition */
+#ifdef GIF_LIB_VERSION
 extern GifFileType *EGifOpen(void *userData, OutputFunc writeFunc);
+#endif
 
 /* Data structure used for callback */
 typedef struct
@@ -245,7 +249,9 @@ DGifSlurpMono(GifFileType * GifFile, Sav
 					if (DGifGetExtensionNext(GifFile, &ExtData) == GIF_ERROR) {
 						return (GIF_ERROR);
 					}
+#if GIFLIB_MAJOR < 5
 					temp_save.Function = 0;
+#endif
 				}
 				break;
 			}
@@ -304,9 +310,17 @@ gdip_load_gif_image (void *stream, GpIma
 	loop_counter = FALSE;
 
 	if (from_file) {
+#if GIFLIB_MAJOR >= 5
+		gif = DGifOpen(stream, &gdip_gif_fileinputfunc, NULL);
+#else 
 		gif = DGifOpen(stream, &gdip_gif_fileinputfunc);
+#endif
 	} else {
+#if GIFLIB_MAJOR >= 5
+		gif = DGifOpen (stream, &gdip_gif_inputfunc, NULL);
+#else
 		gif = DGifOpen (stream, &gdip_gif_inputfunc);
+#endif
 	}
 	
 	if (gif == NULL) {
@@ -662,9 +676,17 @@ gdip_save_gif_image (void *stream, GpIma
 	}
 
 	if (from_file) {
+#if GIFLIB_MAJOR >= 5
+		fp = EGifOpenFileName (stream, 0, NULL);
+#else
 		fp = EGifOpenFileName (stream, 0);
+#endif
 	} else {
+#if GIFLIB_MAJOR >= 5
+		fp = EGifOpen (stream, gdip_gif_outputfunc, NULL);
+#else
 		fp = EGifOpen (stream, gdip_gif_outputfunc);
+#endif
 	}
 		
 	if (!fp) {
@@ -703,7 +725,11 @@ gdip_save_gif_image (void *stream, GpIma
 					goto error; 
 				}
 
+#if GIFLIB_MAJOR >= 5
+				cmap = GifMakeMapObject(cmap_size, 0);
+#else
 				cmap = MakeMapObject(cmap_size, 0);
+#endif
 
 				pixbuf = GdipAlloc(pixbuf_size);
 				if (pixbuf == NULL) {
@@ -794,7 +820,11 @@ gdip_save_gif_image (void *stream, GpIma
 				pixbuf = pixbuf_org;
 			} else {
 				cmap_size = 256;
+#if GIFLIB_MAJOR >= 5
+				cmap  = GifMakeMapObject (cmap_size, 0);
+#else
 				cmap  = MakeMapObject (cmap_size, 0);
+#endif
 
 				red = GdipAlloc(pixbuf_size);
 				green = GdipAlloc(pixbuf_size);
@@ -825,13 +855,21 @@ gdip_save_gif_image (void *stream, GpIma
 						v += 4;
 					}
 				}
+#if GIFLIB_MAJOR >= 5
+				if (GifQuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
+#else
 				if (QuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
+#endif
 						red,  green, blue, pixbuf, cmap->Colors) == GIF_ERROR) {
 					goto error;
 				}
 			}
 
+#if GIFLIB_MAJOR >= 5
+			cmap->BitsPerPixel = GifBitSize (cmap_size);
+#else
 			cmap->BitsPerPixel = BitSize (cmap_size);
+#endif
 			cmap->ColorCount = 1 << cmap->BitsPerPixel;
 
 			if ((frame == 0) && (k == 0)) {
@@ -849,8 +887,15 @@ gdip_save_gif_image (void *stream, GpIma
 						Buffer[0] = 1;
 						Buffer[1] = ptr[0];
 						Buffer[2] = ptr[1];
+#if GIFLIB_MAJOR >= 5
+						EGifPutExtensionLeader(fp, APPLICATION_EXT_FUNC_CODE);
+						EGifPutExtensionBlock(fp, 11, "NETSCAPE2.0");
+						EGifPutExtensionBlock(fp, 3, Buffer);
+						EGifPutExtensionTrailer(fp);
+#else
 						EGifPutExtensionFirst(fp, APPLICATION_EXT_FUNC_CODE, 11, "NETSCAPE2.0");
 						EGifPutExtensionLast(fp, APPLICATION_EXT_FUNC_CODE, 3, Buffer);
+#endif
 					}
 				}
 
@@ -902,7 +947,11 @@ gdip_save_gif_image (void *stream, GpIma
 				pixbuf += bitmap_data->width;
 			}
 
+#if GIFLIB_MAJOR >= 5
+			GifFreeMapObject (cmap);
+#else
 			FreeMapObject (cmap);
+#endif
 			if (red != NULL) {
 				GdipFree (red);
 			}
