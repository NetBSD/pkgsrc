$NetBSD: patch-IMG__pcx.c,v 1.1 2020/05/14 16:08:07 nia Exp $

Various sanity fixes from upstream preventing potential
security problems.

--- IMG_pcx.c.orig	2012-01-21 01:51:33.000000000 +0000
+++ IMG_pcx.c
@@ -100,6 +100,8 @@ SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *s
 	Uint8 *row, *buf = NULL;
 	char *error = NULL;
 	int bits, src_bits;
+	int count = 0;
+	Uint8 ch;
 
 	if ( !src ) {
 		/* The error message has been set in SDL_RWFromFile */
@@ -127,37 +129,37 @@ SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *s
 		bits = 8;
 	} else if(pcxh.BitsPerPixel == 8 && pcxh.NPlanes == 3) {
 		bits = 24;
-		if ( SDL_BYTEORDER == SDL_LIL_ENDIAN ) {
-			Rmask = 0x000000FF;
-			Gmask = 0x0000FF00;
-			Bmask = 0x00FF0000;
-		} else {
-			Rmask = 0xFF0000;
-			Gmask = 0x00FF00;
-			Bmask = 0x0000FF;
-		}
+#if SDL_BYTEORDER == SDL_LIL_ENDIAN
+		Rmask = 0x000000FF;
+		Gmask = 0x0000FF00;
+		Bmask = 0x00FF0000;
+#else
+		Rmask = 0xFF0000;
+		Gmask = 0x00FF00;
+		Bmask = 0x0000FF;
+#endif
 	} else {
 		error = "unsupported PCX format";
 		goto done;
 	}
 	surface = SDL_AllocSurface(SDL_SWSURFACE, width, height,
 				   bits, Rmask, Gmask, Bmask, Amask);
-	if ( surface == NULL )
+	if ( surface == NULL ) {
 		goto done;
+	}
 
 	bpl = pcxh.NPlanes * pcxh.BytesPerLine;
-	if (bpl > surface->pitch) {
-		error = "bytes per line is too large (corrupt?)";
+	buf = (Uint8 *)calloc(bpl, 1);
+	if (!buf) {
+		error = "Out of memory";
+		goto done;
 	}
-	buf = malloc(bpl);
-	row = surface->pixels;
+	row = (Uint8 *)surface->pixels;
 	for ( y=0; y<surface->h; ++y ) {
 		/* decode a scan line to a temporary buffer first */
-		int i, count = 0;
-		Uint8 ch;
-		Uint8 *dst = (src_bits == 8) ? row : buf;
+		int i;
 		if ( pcxh.Encoding == 0 ) {
-			if(!SDL_RWread(src, dst, bpl, 1)) {
+			if(!SDL_RWread(src, buf, bpl, 1)) {
 				error = "file truncated";
 				goto done;
 			}
@@ -168,46 +170,54 @@ SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *s
 						error = "file truncated";
 						goto done;
 					}
-					if( (ch & 0xc0) == 0xc0) {
-						count = ch & 0x3f;
+					if (ch < 0xc0) {
+						count = 1;
+					} else {
+						count = ch - 0xc0;
 						if(!SDL_RWread(src, &ch, 1, 1)) {
 							error = "file truncated";
 							goto done;
 						}
-					} else
-						count = 1;
+					}
 				}
-				dst[i] = ch;
+				buf[i] = ch;
 				count--;
 			}
 		}
 
 		if(src_bits <= 4) {
 			/* expand planes to 1 byte/pixel */
-			Uint8 *src = buf;
+			Uint8 *innerSrc = buf;
 			int plane;
 			for(plane = 0; plane < pcxh.NPlanes; plane++) {
-				int i, j, x = 0;
-				for(i = 0; i < pcxh.BytesPerLine; i++) {
-					Uint8 byte = *src++;
-					for(j = 7; j >= 0; j--) {
-						unsigned bit = (byte >> j) & 1;
+				int j, k, x = 0;
+				for(j = 0; j < pcxh.BytesPerLine; j++) {
+					Uint8 byte = *innerSrc++;
+					for(k = 7; k >= 0; k--) {
+						unsigned bit = (byte >> k) & 1;
 						/* skip padding bits */
-						if (i * 8 + j >= width)
+						if (j * 8 + k >= width)
 							continue;
 						row[x++] |= bit << plane;
 					}
 				}
 			}
+		} else if(src_bits == 8) {
+			/* Copy the row directly */
+			memcpy(row, buf, SDL_min(width, bpl));
  		} else if(src_bits == 24) {
 			/* de-interlace planes */
-			Uint8 *src = buf;
+			Uint8 *innerSrc = buf;
 			int plane;
 			for(plane = 0; plane < pcxh.NPlanes; plane++) {
 				int x;
-				dst = row + plane;
+				Uint8 *dst = row + plane;
 				for(x = 0; x < width; x++) {
-					*dst = *src++;
+					if (dst >= row+surface->pitch) {
+						error = "decoding out of bounds (corrupt?)";
+						goto done;
+					}
+					*dst = *innerSrc++;
 					dst += pcxh.NPlanes;
 				}
 			}
@@ -227,8 +237,9 @@ SDL_Surface *IMG_LoadPCX_RW(SDL_RWops *s
 			/* look for a 256-colour palette */
 			do {
 				if ( !SDL_RWread(src, &ch, 1, 1)) {
-					error = "file truncated";
-					goto done;
+					/* Couldn't find the palette, try the end of the file */
+					SDL_RWseek(src, -768, RW_SEEK_END);
+					break;
 				}
 			} while ( ch != 12 );
 
