$NetBSD: patch-utils_TkCximage_src_CxImage_ximapng.cpp,v 1.4 2011/08/04 23:58:36 wiz Exp $

Fix build with png-1.5.
https://sourceforge.net/tracker/?func=detail&aid=3386428&group_id=54091&atid=472655

--- utils/TkCximage/src/CxImage/ximapng.cpp.orig	2010-01-29 09:09:27.000000000 +0000
+++ utils/TkCximage/src/CxImage/ximapng.cpp
@@ -15,7 +15,7 @@
 void CxImagePNG::ima_png_error(png_struct *png_ptr, char *message)
 {
 	strcpy(info.szLastError,message);
-	longjmp(png_ptr->jmpbuf, 1);
+	longjmp(png_jmpbuf(png_ptr), 1);
 }
 ////////////////////////////////////////////////////////////////////////////////
 #if CXIMAGE_SUPPORT_DECODE
@@ -62,7 +62,7 @@ bool CxImagePNG::Decode(CxFile *hFile)
     /* Set error handling if you are using the setjmp/longjmp method (this is
     * the normal method of doing things with libpng).  REQUIRED unless you
     * set up your own error handlers in the png_create_read_struct() earlier. */
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		/* Free all of the memory associated with the png_ptr and info_ptr */
 		delete [] row_pointers;
 		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
@@ -77,15 +77,15 @@ bool CxImagePNG::Decode(CxFile *hFile)
 	png_read_info(png_ptr, info_ptr);
 
 	if (info.nEscape == -1){
-		head.biWidth = info_ptr->width;
-		head.biHeight= info_ptr->height;
+		head.biWidth = png_get_image_width(png_ptr, info_ptr);
+		head.biHeight= png_get_image_height(png_ptr, info_ptr);
 		info.dwType = CXIMAGE_FORMAT_PNG;
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	/* calculate new number of channels */
 	int channels=0;
-	switch(info_ptr->color_type){
+	switch(png_get_color_type(png_ptr, info_ptr)){
 	case PNG_COLOR_TYPE_GRAY:
 	case PNG_COLOR_TYPE_PALETTE:
 		channels = 1;
@@ -101,71 +101,76 @@ bool CxImagePNG::Decode(CxFile *hFile)
 		break;
 	default:
 		strcpy(info.szLastError,"unknown PNG color type");
-		longjmp(png_ptr->jmpbuf, 1);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	//find the right pixel depth used for cximage
-	int pixel_depth = info_ptr->pixel_depth;
+#if MIGHT_BE_BUGGY
+	int pixel_depth = png_get_pixel_depth(png_ptr, info_ptr);
 	if (channels == 1 && pixel_depth>8) pixel_depth=8;
+#endif
+	int pixel_depth;
+	if (channels == 1) pixel_depth=8;
 	if (channels == 2) pixel_depth=8;
 	if (channels >= 3) pixel_depth=24;
 
-	if (!Create(info_ptr->width, info_ptr->height, pixel_depth, CXIMAGE_FORMAT_PNG)){
-		longjmp(png_ptr->jmpbuf, 1);
+	if (!Create(png_get_image_width(png_ptr, info_ptr), png_get_image_height(png_ptr, info_ptr), pixel_depth, CXIMAGE_FORMAT_PNG)){
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 
 	/* get metrics */
-	switch (info_ptr->phys_unit_type)
+	png_uint_32 res_x, res_y;
+	int unit_type;
+	png_get_pHYs_dpi(png_ptr, info_ptr, &res_x, &res_y, &unit_type);
+	switch (unit_type)
 	{
 	case PNG_RESOLUTION_UNKNOWN:
-		SetXDPI(info_ptr->x_pixels_per_unit);
-		SetYDPI(info_ptr->y_pixels_per_unit);
+		SetXDPI(res_x);
+		SetYDPI(res_y);
 		break;
 	case PNG_RESOLUTION_METER:
-		SetXDPI((long)floor(info_ptr->x_pixels_per_unit * 254.0 / 10000.0 + 0.5));
-		SetYDPI((long)floor(info_ptr->y_pixels_per_unit * 254.0 / 10000.0 + 0.5));
+		SetXDPI((long)floor(res_x * 254.0 / 10000.0 + 0.5));
+		SetYDPI((long)floor(res_y * 254.0 / 10000.0 + 0.5));
 		break;
 	}
 
-	if (info_ptr->num_palette>0){
-		SetPalette((rgb_color*)info_ptr->palette,info_ptr->num_palette);
-		SetClrImportant(info_ptr->num_palette);
-	} else if (info_ptr->bit_depth ==2) { //<DP> needed for 2 bpp grayscale PNGs
+	png_colorp palette;
+	int num_palette;
+	png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette);
+	if (num_palette>0){
+		SetPalette((rgb_color*)palette,num_palette);
+		SetClrImportant(num_palette);
+	} else if (png_get_bit_depth(png_ptr, info_ptr) ==2) { //<DP> needed for 2 bpp grayscale PNGs
 		SetPaletteColor(0,0,0,0);
 		SetPaletteColor(1,85,85,85);
 		SetPaletteColor(2,170,170,170);
 		SetPaletteColor(3,255,255,255);
 	} else SetGrayPalette(); //<DP> needed for grayscale PNGs
 	
-	int nshift = max(0,(info_ptr->bit_depth>>3)-1)<<3;
+	int nshift = max(0,(png_get_bit_depth(png_ptr, info_ptr)>>3)-1)<<3;
 
-	if (info_ptr->num_trans!=0){ //palette transparency
-		if (info_ptr->num_trans==1){
-			if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE){
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-				info.nBkgndIndex = info_ptr->trans_color.index;
-#else
-				info.nBkgndIndex = info_ptr->trans_values.index;
-#endif
+png_uint_32    png_get_tRNS   (png_const_structp   png_ptr,   png_infop
+info_ptr,  png_bytep  *trans_alpha,   int   *num_trans,   png_color_16p
+*trans_color);
+	png_bytep trans_alpha;
+	int num_trans;
+	png_color_16p trans_color;
+	png_get_tRNS(png_ptr, info_ptr, &trans_alpha, &num_trans, &trans_color);
+	if (num_trans!=0){ //palette transparency
+		if (num_trans==1){
+			if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE){
+				info.nBkgndIndex = trans_color->index;
 			} else{
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-				info.nBkgndIndex = info_ptr->trans_color.gray>>nshift;
-#else
-				info.nBkgndIndex = info_ptr->trans_values.gray>>nshift;
-#endif
+				info.nBkgndIndex = trans_color->gray>>nshift;
 			}
 		}
-		if (info_ptr->num_trans>1){
+		if (num_trans>1){
 			RGBQUAD* pal=GetPalette();
 			if (pal){
 				DWORD ip;
-				for (ip=0;ip<min(head.biClrUsed,(unsigned long)info_ptr->num_trans);ip++)
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-					pal[ip].rgbReserved=info_ptr->trans_alpha[ip];
-#else
-					pal[ip].rgbReserved=info_ptr->trans[ip];
-#endif
-				for (ip=info_ptr->num_trans;ip<head.biClrUsed;ip++){
+				for (ip=0;ip<min(head.biClrUsed,(unsigned long)num_trans);ip++)
+					pal[ip].rgbReserved=trans_alpha[ip];
+				for (ip=num_trans;ip<head.biClrUsed;ip++){
 					pal[ip].rgbReserved=255;
 				}
 				info.bAlphaPaletteEnabled=true;
@@ -178,15 +183,9 @@ bool CxImagePNG::Decode(CxFile *hFile)
 		int num_trans;
 		png_color_16 *image_background;
 		if (png_get_tRNS(png_ptr, info_ptr, &trans, &num_trans, &image_background)){
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-			info.nBkgndColor.rgbRed   = (BYTE)(info_ptr->trans_color.red>>nshift);
-			info.nBkgndColor.rgbGreen = (BYTE)(info_ptr->trans_color.green>>nshift);
-			info.nBkgndColor.rgbBlue  = (BYTE)(info_ptr->trans_color.blue>>nshift);
-#else
-			info.nBkgndColor.rgbRed   = (BYTE)(info_ptr->trans_values.red>>nshift);
-			info.nBkgndColor.rgbGreen = (BYTE)(info_ptr->trans_values.green>>nshift);
-			info.nBkgndColor.rgbBlue  = (BYTE)(info_ptr->trans_values.blue>>nshift);
-#endif
+			info.nBkgndColor.rgbRed   = (BYTE)(trans_color->red>>nshift);
+			info.nBkgndColor.rgbGreen = (BYTE)(trans_color->green>>nshift);
+			info.nBkgndColor.rgbBlue  = (BYTE)(trans_color->blue>>nshift);
 			info.nBkgndColor.rgbReserved = 0;
 			info.nBkgndIndex = 0;
 		}
@@ -202,15 +201,15 @@ bool CxImagePNG::Decode(CxFile *hFile)
 	}
 
 	// <vho> - flip the RGB pixels to BGR (or RGBA to BGRA)
-	if (info_ptr->color_type & PNG_COLOR_MASK_COLOR){
+	if (png_get_color_type(png_ptr, info_ptr) & PNG_COLOR_MASK_COLOR){
 		png_set_bgr(png_ptr);
 	}
 
 	// <vho> - handle cancel
-	if (info.nEscape) longjmp(png_ptr->jmpbuf, 1);
+	if (info.nEscape) longjmp(png_jmpbuf(png_ptr), 1);
 
 	// row_bytes is the width x number of channels x (bit-depth / 8)
-	row_pointers = new BYTE[info_ptr->rowbytes + 8];
+	row_pointers = new BYTE[png_get_rowbytes(png_ptr, info_ptr) + 8];
 
 	// turn on interlace handling
 	int number_passes = png_set_interlace_handling(png_ptr);
@@ -221,8 +220,10 @@ bool CxImagePNG::Decode(CxFile *hFile)
 		SetCodecOption(0);
 	}
 
-	int chan_offset = info_ptr->bit_depth >> 3;
-	int pixel_offset = info_ptr->pixel_depth >> 3;
+	int bit_depth = png_get_bit_depth(png_ptr, info_ptr);
+	int chan_offset = bit_depth >> 3;
+	//int pixel_offset = info_ptr->pixel_depth >> 3;
+	int pixel_offset = (bit_depth * channels) >> 3;
 
 	for (int pass=0; pass < number_passes; pass++) {
 		iter.Upset();
@@ -230,7 +231,7 @@ bool CxImagePNG::Decode(CxFile *hFile)
 		do	{
 
 			// <vho> - handle cancel
-			if (info.nEscape) longjmp(png_ptr->jmpbuf, 1);
+			if (info.nEscape) longjmp(png_jmpbuf(png_ptr), 1);
 
 #if CXIMAGE_SUPPORT_ALPHA	// <vho>
 			if (AlphaIsValid()) {
@@ -241,7 +242,7 @@ bool CxImagePNG::Decode(CxFile *hFile)
 				BYTE* prow= iter.GetRow(ay);
 
 				//recover data from previous scan
-				if (info_ptr->interlace_type && pass>0 && pass!=7){
+				if (png_get_interlace_type(png_ptr, info_ptr) && pass>0 && pass!=7){
 					for(ax=0;ax<head.biWidth;ax++){
 						long px = ax * pixel_offset;
 						if (channels == 2){
@@ -278,10 +279,10 @@ bool CxImagePNG::Decode(CxFile *hFile)
 #endif // CXIMAGE_SUPPORT_ALPHA		// vho
 			{
 				//recover data from previous scan
-				if (info_ptr->interlace_type && pass>0){
-					iter.GetRow(row_pointers, info_ptr->rowbytes);
+				if (png_get_interlace_type(png_ptr, info_ptr) && pass>0){
+					iter.GetRow(row_pointers, png_get_rowbytes(png_ptr, info_ptr));
 					//re-expand buffer for images with bit depth > 8
-					if (info_ptr->bit_depth > 8){
+					if (png_get_bit_depth(png_ptr, info_ptr) > 8){
 						for(long ax=(head.biWidth*channels-1);ax>=0;ax--)
 							row_pointers[ax*chan_offset] = row_pointers[ax];
 					}
@@ -291,15 +292,15 @@ bool CxImagePNG::Decode(CxFile *hFile)
 				png_read_row(png_ptr, row_pointers, NULL);
 
 				//shrink 16 bit depth images down to 8 bits
-				if (info_ptr->bit_depth > 8){
+				if (png_get_bit_depth(png_ptr, info_ptr) > 8){
 					for(long ax=0;ax<(head.biWidth*channels);ax++)
 						row_pointers[ax] = row_pointers[ax*chan_offset];
 				}
 
 				//copy the pixels
-				iter.SetRow(row_pointers, info_ptr->rowbytes);
+				iter.SetRow(row_pointers, png_get_rowbytes(png_ptr, info_ptr));
 				//<DP> expand 2 bpp images only in the last pass
-				if (info_ptr->bit_depth==2 && pass==(number_passes-1))
+				if (png_get_bit_depth(png_ptr, info_ptr)==2 && pass==(number_passes-1))
 					expand2to4bpp(iter.GetRow());
 
 				//go on
@@ -340,6 +341,11 @@ bool CxImagePNG::Encode(CxFile *hFile)
 	BYTE trans[256];	//for transparency (don't move)
 	png_struct *png_ptr;
 	png_info *info_ptr;
+	png_uint_32 width, height;
+	png_byte bit_depth;
+	png_byte color_type;
+	png_byte interlace_type;
+	BYTE channels;
 
   cx_try
   {
@@ -362,9 +368,8 @@ bool CxImagePNG::Encode(CxFile *hFile)
    /* Set error handling.  REQUIRED if you aren't supplying your own
     * error hadnling functions in the png_create_write_struct() call.
     */
-	if (setjmp(png_ptr->jmpbuf)){
+	if (setjmp(png_jmpbuf(png_ptr))){
 		/* If we get here, we had a problem reading the file */
-		if (info_ptr->palette) free(info_ptr->palette);
 		png_destroy_write_struct(&png_ptr,  (png_infopp)&info_ptr);
 		cx_throw("Error saving PNG file");
 	}
@@ -376,20 +381,18 @@ bool CxImagePNG::Encode(CxFile *hFile)
     png_set_write_fn(png_ptr,hFile,/*(png_rw_ptr)*/user_write_data,/*(png_flush_ptr)*/user_flush_data);
 
 	/* set the file information here */
-	info_ptr->width = GetWidth();
-	info_ptr->height = GetHeight();
-	info_ptr->pixel_depth = (BYTE)GetBpp();
-	info_ptr->channels = (GetBpp()>8) ? (BYTE)3: (BYTE)1;
-	info_ptr->bit_depth = (BYTE)(GetBpp()/info_ptr->channels);
-	info_ptr->compression_type = info_ptr->filter_type = 0;
-	info_ptr->valid = 0;
+	width = GetWidth();
+	height = GetHeight();
+	//pixel_depth = (BYTE)GetBpp();
+	channels = (GetBpp()>8) ? (BYTE)3: (BYTE)1;
+	bit_depth = (BYTE)(GetBpp()/channels);
 
 	switch(GetCodecOption(CXIMAGE_FORMAT_PNG)){
 	case 1:
-		info_ptr->interlace_type = PNG_INTERLACE_ADAM7;
+		interlace_type = PNG_INTERLACE_ADAM7;
 		break;
 	default:
-		info_ptr->interlace_type = PNG_INTERLACE_NONE;
+		interlace_type = PNG_INTERLACE_NONE;
 	}
 
 	/* set compression level */
@@ -399,19 +402,19 @@ bool CxImagePNG::Encode(CxFile *hFile)
 
 	if (GetNumColors()){
 		if (bGrayScale){
-			info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
+			color_type = PNG_COLOR_TYPE_GRAY;
 		} else {
-			info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
+			color_type = PNG_COLOR_TYPE_PALETTE;
 		}
 	} else {
-		info_ptr->color_type = PNG_COLOR_TYPE_RGB;
+		color_type = PNG_COLOR_TYPE_RGB;
 	}
 #if CXIMAGE_SUPPORT_ALPHA
 	if (AlphaIsValid()){
-		info_ptr->color_type |= PNG_COLOR_MASK_ALPHA;
-		info_ptr->channels++;
-		info_ptr->bit_depth = 8;
-		info_ptr->pixel_depth += 8;
+		color_type |= PNG_COLOR_MASK_ALPHA;
+		channels++;
+		bit_depth = 8;
+		//pixel_depth += 8;
 	}
 #endif
 
@@ -428,29 +431,21 @@ bool CxImagePNG::Encode(CxFile *hFile)
 	/* set metrics */
 	png_set_pHYs(png_ptr, info_ptr, head.biXPelsPerMeter, head.biYPelsPerMeter, PNG_RESOLUTION_METER);
 
-	png_set_IHDR(png_ptr, info_ptr, info_ptr->width, info_ptr->height, info_ptr->bit_depth,
-				info_ptr->color_type, info_ptr->interlace_type,
+	png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth,
+				color_type, interlace_type,
 				PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
 
 	//<DP> simple transparency
 	if (info.nBkgndIndex >= 0){
-		info_ptr->num_trans = 1;
-		info_ptr->valid |= PNG_INFO_tRNS;
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-		info_ptr->trans_alpha = trans;
-		info_ptr->trans_color.index = (BYTE)info.nBkgndIndex;
-		info_ptr->trans_color.red   = tc.rgbRed;
-		info_ptr->trans_color.green = tc.rgbGreen;
-		info_ptr->trans_color.blue  = tc.rgbBlue;
-		info_ptr->trans_color.gray  = info_ptr->trans_color.index;
-#else
-		info_ptr->trans = trans;
-		info_ptr->trans_values.index = (BYTE)info.nBkgndIndex;
-		info_ptr->trans_values.red   = tc.rgbRed;
-		info_ptr->trans_values.green = tc.rgbGreen;
-		info_ptr->trans_values.blue  = tc.rgbBlue;
-		info_ptr->trans_values.gray  = info_ptr->trans_values.index;
-#endif
+		png_color_16 trans_color;
+
+		trans_color.index = (BYTE)info.nBkgndIndex;
+		trans_color.red   = tc.rgbRed;
+		trans_color.green = tc.rgbGreen;
+		trans_color.blue  = tc.rgbBlue;
+		trans_color.gray  = (BYTE)info.nBkgndIndex;
+
+		png_set_tRNS(png_ptr, info_ptr, trans, 1, &trans_color);
 
 		// the transparency indexes start from 0 for non grayscale palette
 		if (!bGrayScale && head.biClrUsed && info.nBkgndIndex)
@@ -459,30 +454,27 @@ bool CxImagePNG::Encode(CxFile *hFile)
 
 	/* set the palette if there is one */
 	if (GetPalette()){
-		if (!bGrayScale){
-			info_ptr->valid |= PNG_INFO_PLTE;
-		}
-
 		int nc = GetClrImportant();
 		if (nc==0) nc = GetNumColors();
 
 		if (info.bAlphaPaletteEnabled){
 			for(WORD ip=0; ip<nc;ip++)
 				trans[ip]=GetPaletteColor((BYTE)ip).rgbReserved;
-			info_ptr->num_trans = (WORD)nc;
-			info_ptr->valid |= PNG_INFO_tRNS;
-#if PNG_LIBPNG_VER_MAJOR >= 1 && PNG_LIBPNG_VER_MINOR >= 4
-			info_ptr->trans_alpha = trans;
-#else
-			info_ptr->trans = trans;
-#endif
+			png_set_tRNS(png_ptr, info_ptr, trans, (WORD)nc, NULL);
 		}
 
 		// copy the palette colors
-		info_ptr->palette = new png_color[nc];
-		info_ptr->num_palette = (png_uint_16) nc;
-		for (int i=0; i<nc; i++)
-			GetPaletteColor(i, &info_ptr->palette[i].red, &info_ptr->palette[i].green, &info_ptr->palette[i].blue);
+		if (!bGrayScale) {
+			png_color *palette;
+
+			palette = (png_color *)png_malloc(png_ptr, nc*sizeof(palette[0]));
+			for (int i=0; i<nc; i++)
+				GetPaletteColor(i, &palette[i].red, &palette[i].green, &palette[i].blue);
+			png_set_PLTE(png_ptr, info_ptr, palette, nc);
+			png_data_freer(png_ptr, info_ptr,
+				       PNG_DESTROY_WILL_FREE_DATA,
+				       PNG_FREE_PLTE);
+		}
 	}  
 
 #if CXIMAGE_SUPPORT_ALPHA	// <vho>
@@ -496,8 +488,8 @@ bool CxImagePNG::Encode(CxFile *hFile)
 	}	}	}
 #endif // CXIMAGE_SUPPORT_ALPHA	// <vho>
 
-	int row_size = max(info.dwEffWidth, info_ptr->width*info_ptr->channels*(info_ptr->bit_depth/8));
-	info_ptr->rowbytes = row_size;
+	int row_size = max(info.dwEffWidth, png_get_rowbytes(png_ptr, info_ptr));
+	//info_ptr->rowbytes = row_size;
 	BYTE *row_pointers = new BYTE[row_size];
 
 	/* write the file information */
@@ -515,7 +507,7 @@ bool CxImagePNG::Encode(CxFile *hFile)
 			if (AlphaIsValid()){
 				for (long ax=head.biWidth-1; ax>=0;ax--){
 					c = BlindGetPixelColor(ax,ay);
-					int px = ax * info_ptr->channels;
+					int px = ax * png_get_channels(png_ptr, info_ptr);
 					if (!bGrayScale){
 						row_pointers[px++]=c.rgbRed;
 						row_pointers[px++]=c.rgbGreen;
@@ -530,7 +522,7 @@ bool CxImagePNG::Encode(CxFile *hFile)
 #endif //CXIMAGE_SUPPORT_ALPHA	// <vho>
 			{
 				iter.GetRow(row_pointers, row_size);
-				if (info_ptr->color_type == PNG_COLOR_TYPE_RGB) //HACK BY OP
+				if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB) //HACK BY OP
 					RGBtoBGR(row_pointers, row_size);
 				png_write_row(png_ptr, row_pointers);
 			}
@@ -547,12 +539,6 @@ bool CxImagePNG::Encode(CxFile *hFile)
 	/* It is REQUIRED to call this to finish writing the rest of the file */
 	png_write_end(png_ptr, info_ptr);
 
-	/* if you malloced the palette, free it here */
-	if (info_ptr->palette){
-		delete [] (info_ptr->palette);
-		info_ptr->palette = NULL;
-	}
-
 	/* clean up after the write, and free any memory allocated */
 	png_destroy_write_struct(&png_ptr, (png_infopp)&info_ptr);
 
