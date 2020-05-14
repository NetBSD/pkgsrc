$NetBSD: patch-IMG__lbm.c,v 1.1 2020/05/14 16:08:07 nia Exp $

Various sanity fixes from upstream preventing potential
security problems.

--- IMG_lbm.c.orig	2012-01-21 01:51:33.000000000 +0000
+++ IMG_lbm.c
@@ -187,7 +187,12 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 
 		if ( !memcmp( id, "CMAP", 4 ) ) /* palette ( Color Map ) */
 		{
-			if ( !SDL_RWread( src, &colormap, size, 1 ) )
+			if (size > sizeof (colormap)) {
+				error="colormap size is too large";
+				goto done;
+			}
+
+			if ( !SDL_RWread( src, colormap, size, 1 ) )
 			{
 				error="error reading CMAP chunk";
 				goto done;
@@ -242,14 +247,14 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 	/* Allocate memory for a temporary buffer ( used for
            decompression/deinterleaving ) */
 
-	MiniBuf = (void *)malloc( bytesperline * (nbplanes + stencil) );
+	MiniBuf = (Uint8 *)malloc( bytesperline * (nbplanes + stencil) );
 	if ( MiniBuf == NULL )
 	{
-		error="no enough memory for temporary buffer";
+		error="not enough memory for temporary buffer";
 		goto done;
 	}
 
-	if ( ( Image = SDL_CreateRGBSurface( SDL_SWSURFACE, width, bmhd.h, (bmhd.planes==24 || flagHAM==1)?24:8, 0, 0, 0, 0 ) ) == NULL )
+	if ( ( Image = SDL_CreateRGBSurface( SDL_SWSURFACE, width, bmhd.h, (nbplanes==24 || flagHAM==1)?24:8, 0, 0, 0, 0 ) ) == NULL )
 	   goto done;
 
 	if ( bmhd.mask & 2 )               /* There is a transparent color */
@@ -276,7 +281,7 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 		/* The 32 last colors are the same but divided by 2 */
 		/* Some Amiga pictures save 64 colors with 32 last wrong colors, */
 		/* they shouldn't !, and here we overwrite these 32 bad colors. */
-		if ( (nbcolors==32 || flagEHB ) && (1<<bmhd.planes)==64 )
+		if ( (nbcolors==32 || flagEHB ) && (1<<nbplanes)==64 )
 		{
 			nbcolors = 64;
 			ptr = &colormap[0];
@@ -290,8 +295,8 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 
 		/* If nbcolors < 2^nbplanes, repeat the colormap */
 		/* This happens when pictures have a stencil mask */
-		if ( nbrcolorsfinal > (1<<bmhd.planes) ) {
-			nbrcolorsfinal = (1<<bmhd.planes);
+		if ( nbrcolorsfinal > (1<<nbplanes) ) {
+			nbrcolorsfinal = (1<<nbplanes);
 		}
 		for ( i=nbcolors; i < (Uint32)nbrcolorsfinal; i++ )
 		{
@@ -365,7 +370,7 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 
 		/* One line has been read, store it ! */
 
-		ptr = Image->pixels;
+		ptr = (Uint8 *)Image->pixels;
 		if ( nbplanes==24 || flagHAM==1 )
 			ptr += h * width * 3;
 		else
@@ -449,19 +454,15 @@ SDL_Surface *IMG_LoadLBM_RW( SDL_RWops *
 						{
 							finalcolor = pixelcolor;
 						}
-						if ( SDL_BYTEORDER == SDL_LIL_ENDIAN )
-						{
-							*ptr++ = (Uint8)(finalcolor>>16);
-							*ptr++ = (Uint8)(finalcolor>>8);
-							*ptr++ = (Uint8)(finalcolor);
-						}
-						else
-						{
-							*ptr++ = (Uint8)(finalcolor);
-							*ptr++ = (Uint8)(finalcolor>>8);
-							*ptr++ = (Uint8)(finalcolor>>16);
-						}
-
+#if SDL_BYTEORDER == SDL_LIL_ENDIAN
+						*ptr++ = (Uint8)(finalcolor>>16);
+						*ptr++ = (Uint8)(finalcolor>>8);
+						*ptr++ = (Uint8)(finalcolor);
+#else
+						*ptr++ = (Uint8)(finalcolor);
+						*ptr++ = (Uint8)(finalcolor>>8);
+						*ptr++ = (Uint8)(finalcolor>>16);
+#endif
 						maskBit = maskBit>>1;
 					}
 				}
