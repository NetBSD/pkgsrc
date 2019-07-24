$NetBSD: patch-src_video_SDL__pixels.c,v 1.2 2019/07/24 14:08:23 micha Exp $

CVE-2019-7637: Fix in integer overflow in SDL_CalculatePitch
From https://hg.libsdl.org/SDL/rev/9b0e5c555c0f

Local variable 'byte':
Declaration moved out of for loop because this syntax requires C99
(breaks e.g. NetBSD 7 because LANGUAGES= c99 is not defined by package)

--- src/video/SDL_pixels.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/SDL_pixels.c
@@ -286,26 +286,54 @@ void SDL_DitherColors(SDL_Color *colors,
 	}
 }
 /* 
- * Calculate the pad-aligned scanline width of a surface
+ * Calculate the pad-aligned scanline width of a surface. Return 0 in case of
+ * an error.
  */
 Uint16 SDL_CalculatePitch(SDL_Surface *surface)
 {
-	Uint16 pitch;
+	unsigned int pitch = 0;
+	Uint8 byte;  // Requires C99 if defined inside for loop
 
 	/* Surface should be 4-byte aligned for speed */
-	pitch = surface->w*surface->format->BytesPerPixel;
+	/* The code tries to prevent from an Uint16 overflow. */;
+	for (byte = surface->format->BytesPerPixel; byte; byte--) {
+		pitch += (unsigned int)surface->w;
+		if (pitch < surface->w) {
+			SDL_SetError("A scanline is too wide");
+			return(0);
+		}
+	}
 	switch (surface->format->BitsPerPixel) {
 		case 1:
-			pitch = (pitch+7)/8;
+			if (pitch % 8) {
+				pitch = pitch / 8 + 1;
+			} else {
+				pitch = pitch / 8;
+			}
 			break;
 		case 4:
-			pitch = (pitch+1)/2;
+			if (pitch % 2) {
+				pitch = pitch / 2 + 1;
+			} else {
+				pitch = pitch / 2;
+			}
 			break;
 		default:
 			break;
 	}
-	pitch = (pitch + 3) & ~3;	/* 4-byte aligning */
-	return(pitch);
+	/* 4-byte aligning */
+	if (pitch & 3) {
+		if (pitch + 3 < pitch) {
+			SDL_SetError("A scanline is too wide");
+			return(0);
+		}
+		pitch = (pitch + 3) & ~3;
+	}
+	if (pitch > 0xFFFF) {
+		SDL_SetError("A scanline is too wide");
+		return(0);
+	}
+	return((Uint16)pitch);
 }
 /*
  * Match an RGB value to a particular palette index
