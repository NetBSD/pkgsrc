$NetBSD: patch-src_gifcodec.c,v 1.3 2014/05/20 20:20:43 adam Exp $

Fixes for giflib 5.x

--- src/gifcodec.c.orig	2011-12-02 17:23:12.000000000 +0000
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
@@ -129,7 +133,7 @@ AddExtensionBlockMono(SavedImage *New, i
 
 	if (ExtData) {
 		memcpy(ep->Bytes, ExtData, Len);
-		ep->Function = New->Function;
+		ep->Function = New->ExtensionBlocks[New->ExtensionBlockCount++].Function;
 	}
 
 	return (GIF_OK);
@@ -232,7 +236,7 @@ DGifSlurpMono(GifFileType * GifFile, Sav
 			}
 
 			case EXTENSION_RECORD_TYPE: {
-				if (DGifGetExtension(GifFile, &temp_save.Function, &ExtData) == GIF_ERROR) {
+				if (DGifGetExtension(GifFile, &temp_save.ExtensionBlocks[temp_save.ExtensionBlockCount].Function, &ExtData) == GIF_ERROR) {
 					return (GIF_ERROR);
 				}
 
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
@@ -304,9 +310,9 @@ gdip_load_gif_image (void *stream, GpIma
 	loop_counter = FALSE;
 
 	if (from_file) {
-		gif = DGifOpen(stream, &gdip_gif_fileinputfunc);
+		gif = DGifOpen(stream, &gdip_gif_fileinputfunc, NULL);
 	} else {
-		gif = DGifOpen (stream, &gdip_gif_inputfunc);
+		gif = DGifOpen(stream, &gdip_gif_inputfunc, NULL);
 	}
 	
 	if (gif == NULL) {
@@ -581,7 +587,7 @@ gdip_load_gif_image (void *stream, GpIma
 	}
 
 	FreeExtensionMono(&global_extensions);
-	DGifCloseFile (gif);
+	DGifCloseFile(gif, NULL);
 
 	*image = result;
 	return Ok;
@@ -597,7 +603,7 @@ error:	
 
 	if (gif != NULL) {
 		FreeExtensionMono (&global_extensions);
-		DGifCloseFile (gif);
+		DGifCloseFile(gif, NULL);
 	}
 
 	*image = NULL;
@@ -661,9 +667,9 @@ gdip_save_gif_image (void *stream, GpIma
 	}
 
 	if (from_file) {
-		fp = EGifOpenFileName (stream, 0);
+		fp = EGifOpenFileName(stream, 0, NULL);
 	} else {
-		fp = EGifOpen (stream, gdip_gif_outputfunc);
+		fp = EGifOpen(stream, gdip_gif_outputfunc, NULL);
 	}
 		
 	if (!fp) {
@@ -702,7 +708,7 @@ gdip_save_gif_image (void *stream, GpIma
 					goto error; 
 				}
 
-				cmap = MakeMapObject(cmap_size, 0);
+				cmap = GifMakeMapObject(cmap_size, 0);
 
 				pixbuf = GdipAlloc(pixbuf_size);
 				if (pixbuf == NULL) {
@@ -793,7 +799,7 @@ gdip_save_gif_image (void *stream, GpIma
 				pixbuf = pixbuf_org;
 			} else {
 				cmap_size = 256;
-				cmap  = MakeMapObject (cmap_size, 0);
+				cmap  = GifMakeMapObject(cmap_size, 0);
 
 				red = GdipAlloc(pixbuf_size);
 				green = GdipAlloc(pixbuf_size);
@@ -824,13 +830,13 @@ gdip_save_gif_image (void *stream, GpIma
 						v += 4;
 					}
 				}
-				if (QuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
+				if (GifQuantizeBuffer(bitmap_data->width, bitmap_data->height, &cmap_size, 
 						red,  green, blue, pixbuf, cmap->Colors) == GIF_ERROR) {
 					goto error;
 				}
 			}
 
-			cmap->BitsPerPixel = BitSize (cmap_size);
+			cmap->BitsPerPixel = GifBitSize(cmap_size);
 			cmap->ColorCount = 1 << cmap->BitsPerPixel;
 
 			if ((frame == 0) && (k == 0)) {
@@ -848,8 +854,10 @@ gdip_save_gif_image (void *stream, GpIma
 						Buffer[0] = 1;
 						Buffer[1] = ptr[0];
 						Buffer[2] = ptr[1];
-						EGifPutExtensionFirst(fp, APPLICATION_EXT_FUNC_CODE, 11, "NETSCAPE2.0");
-						EGifPutExtensionLast(fp, APPLICATION_EXT_FUNC_CODE, 3, Buffer);
+						EGifPutExtensionLeader(fp, APPLICATION_EXT_FUNC_CODE);
+						EGifPutExtensionBlock(fp, 11, "NETSCAPE2.0");
+						EGifPutExtensionBlock(fp, 3, Buffer);
+						EGifPutExtensionTrailer(fp);
 					}
 				}
 
@@ -901,7 +909,7 @@ gdip_save_gif_image (void *stream, GpIma
 				pixbuf += bitmap_data->width;
 			}
 
-			FreeMapObject (cmap);
+			GifFreeMapObject(cmap);
 			if (red != NULL) {
 				GdipFree (red);
 			}
@@ -923,13 +931,13 @@ gdip_save_gif_image (void *stream, GpIma
 		}
 	}
 
-	EGifCloseFile (fp);	
+	EGifCloseFile(fp, NULL);	
 	
 	return Ok;
 
 error:
 	if (cmap != NULL) {
-		FreeMapObject (cmap);
+		GifFreeMapObject(cmap);
 	}
 
 	if (red != NULL) {
