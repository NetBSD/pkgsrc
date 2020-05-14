$NetBSD: patch-IMG__bmp.c,v 1.1 2020/05/14 16:08:07 nia Exp $

Various sanity fixes from upstream preventing potential
security problems.

--- IMG_bmp.c.orig	2012-01-21 01:51:33.000000000 +0000
+++ IMG_bmp.c
@@ -272,6 +272,11 @@ static SDL_Surface *LoadBMP_RW (SDL_RWop
 		biClrUsed	= SDL_ReadLE32(src);
 		biClrImportant	= SDL_ReadLE32(src);
 	}
+	if (biWidth <= 0 || biHeight == 0) {
+		IMG_SetError("BMP file with bad dimensions (%dx%d)", biWidth, biHeight);
+		was_error = SDL_TRUE;
+		goto done;
+	}
 	if (biHeight < 0) {
 		topDown = SDL_TRUE;
 		biHeight = -biHeight;
@@ -292,6 +297,15 @@ static SDL_Surface *LoadBMP_RW (SDL_RWop
 			ExpandBMP = biBitCount;
 			biBitCount = 8;
 			break;
+		case 0:
+		case 2:
+		case 3:
+		case 5:
+		case 6:
+		case 7:
+			IMG_SetError("%d-bpp BMP images are not supported", biBitCount);
+			was_error = SDL_TRUE;
+			goto done;
 		default:
 			ExpandBMP = 0;
 			break;
@@ -444,7 +458,12 @@ static SDL_Surface *LoadBMP_RW (SDL_RWop
 						goto done;
 					}
 				}
-				*(bits+i) = (pixel>>shift);
+				bits[i] = (pixel >> shift);
+				if (bits[i] >= biClrUsed) {
+					IMG_SetError("A BMP image contains a pixel with a color out of the palette");
+					was_error = SDL_TRUE;
+					goto done;
+				}
 				pixel <<= ExpandBMP;
 			} }
 			break;
@@ -456,6 +475,15 @@ static SDL_Surface *LoadBMP_RW (SDL_RWop
 				was_error = SDL_TRUE;
 				goto done;
 			}
+			if (biBitCount == 8 && palette && biClrUsed < (1 << biBitCount)) {
+				for (i = 0; i < surface->w; ++i) {
+					if (bits[i] >= biClrUsed) {
+						IMG_SetError("A BMP image contains a pixel with a color out of the palette");
+						was_error = SDL_TRUE;
+						goto done;
+					}
+				}
+			}
 #if SDL_BYTEORDER == SDL_BIG_ENDIAN
 			/* Byte-swap the pixels if needed. Note that the 24bpp
 			   case has already been taken care of above. */
@@ -662,6 +690,14 @@ LoadICOCUR_RW(SDL_RWops * src, int type,
         goto done;
     }
 
+    /* sanity check image size, so we don't overflow integers, etc. */
+    if ((biWidth < 0) || (biWidth > 0xFFFFFF) ||
+        (biHeight < 0) || (biHeight > 0xFFFFFF)) {
+        IMG_SetError("Unsupported or invalid ICO dimensions");
+        was_error = SDL_TRUE;
+        goto done;
+    }
+
     /* Create a RGBA surface */
     biHeight = biHeight >> 1;
     //printf("%d x %d\n", biWidth, biHeight);
@@ -679,6 +715,11 @@ LoadICOCUR_RW(SDL_RWops * src, int type,
         if (biClrUsed == 0) {
             biClrUsed = 1 << biBitCount;
         }
+        if (biClrUsed > (sizeof(palette)/sizeof(palette[0]))) {
+            IMG_SetError("Unsupported or incorrect biClrUsed field");
+            was_error = SDL_TRUE;
+            goto done;
+        }
         for (i = 0; i < (int) biClrUsed; ++i) {
             SDL_RWread(src, &palette[i], 4, 1);
         }
