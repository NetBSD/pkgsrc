$NetBSD: patch-image_imlib__loader.c,v 1.1 2011/02/25 17:02:53 wiz Exp $

imlib2 patch from suse.

--- image/imlib_loader.c.orig	2008-01-16 14:52:14.000000000 +0000
+++ image/imlib_loader.c
@@ -6,13 +6,14 @@
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/extensions/shape.h>
-#include <Imlib.h>
+#include <Imlib2.h>
 
 #define IMFILENUM 500
 static char imfile[IMFILENUM][1024];
-static ImlibImage *imdata[IMFILENUM];
+static Imlib_Image *imdata[IMFILENUM];
+static Image *imagedata[IMFILENUM];
 static int imnum;
-static ImlibData *id;
+static Imlib_Context *id;
 
 int imIdent(char *fullname, char *name)
 {
@@ -22,32 +23,71 @@ int imIdent(char *fullname, char *name)
 Image *imLoad(char *fullname, char *name, unsigned int verbose)
 {
 	static Display *disp = NULL;
-	Image *image;
-	ImlibImage *im;
-	ImlibColor shape;
-	unsigned int w,h, size;
-	ImlibImage *search_imdata();
+	Image *image = NULL;
+	Imlib_Image *im;
+	unsigned int w,h, size, i;
+	DATA32 * argb_data;
+	byte * rgb_ptr;
+	Imlib_Image *search_imdata();
 	void regist_imdata();
 
 	if (disp == NULL) {
 		disp=XOpenDisplay(NULL);
 	}
-	if (id == NULL) id=Imlib_init(disp);
-	if ((im = search_imdata(fullname)) == NULL) {
-		im = Imlib_load_image(id, fullname);
+	/*    if (id == NULL) id=Imlib_init(disp); */
+	/* might needs more work */
+	if (id == NULL) {
+		/* dither for non-truecolor displays */
+		imlib_context_set_dither(1);
+		imlib_context_set_display(disp);
+		imlib_context_set_visual(DefaultVisual(disp, DefaultScreen(disp)));
+		imlib_context_set_colormap(DefaultColormap(disp, DefaultScreen(disp)));
+	}
+	if ((im = search_imdata(fullname), image) == NULL) {
+		/* im = Imlib_load_image(id, fullname); */
+		im = imlib_load_image(fullname);
 	}
 	if (im == NULL) {
 		return NULL;
 	}
-	w = im->rgb_width;
-	h = im->rgb_height;
-	size = w * h * 3;
-
-	image = newTrueImage(w, h);
-	memcpy(image->data, im->rgb_data, size);
-	
-	Imlib_get_image_shape(id, im, &shape);
-
+	imlib_context_set_image(im);
+	w = imlib_image_get_width();
+	h = imlib_image_get_height();
+	size = w * h;
+
+	if (image == NULL) image = newTrueImage(w, h);
+
+	/* Imlib2 stores images in ARGB format (32 bpp).  MagicPoint
+	 * wants RGB data (24 bpp). So we need a conversion pass. */
+	argb_data = imlib_image_get_data_for_reading_only();
+	rgb_ptr = image->data;
+	for (i = 0; i < size; ++i)
+	{
+		if ((argb_data[i] >> 24) < 128)
+		{
+			/* If this is a transparent pixel, we store #FE00FE. */
+			*rgb_ptr++ = 0xFE;
+			*rgb_ptr++ = 0x00;
+			*rgb_ptr++ = 0xFE;
+			/* Tell mgp we have transparent pixels. */
+			image->trans = 0xFE00FE;
+		}
+		else if ((argb_data[i] & 0x00FFFFFF) == 0x00FE00FE)
+		{
+		/* If that color is actually used, we substitute something close. */
+		*rgb_ptr++ = 0xFF;
+		*rgb_ptr++ = 0x00;
+		*rgb_ptr++ = 0xFE;
+		}
+		else
+		{
+			/* Otherwise, we can copy the pixel. */
+			*rgb_ptr++ = (argb_data[i] >> 16) & 0xFF; /* red */
+			*rgb_ptr++ = (argb_data[i] >> 8) & 0xFF;  /* green */
+			*rgb_ptr++ = argb_data[i] & 0xFF;         /* blue */
+	 	}
+	}
+#if 0
 	/*
 	 * bug fix for transparent gif handling
 	 * suggested by Jose Geraldo Alves Brito Neto <jgabrito@iq.usp.br>
@@ -57,44 +97,52 @@ Image *imLoad(char *fullname, char *name
 	    ((shape.r & 0xff) << 16) |
 	    ((shape.g & 0xff) <<  8) |
 	    ((shape.b & 0xff) <<  0);
+#endif
 
 	image->title = dupString(name);
 #if 0
 	Imlib_kill_image(id, im);
 #else
-	regist_imdata(name, im);
+	regist_imdata(name, im, image);
 #endif
 	
 	return image;
 }
 
-ImlibImage *search_imdata(char *fullname)
+Imlib_Image *search_imdata(char *fullname, Image *image)
 {
 	int i;
 	for (i = 0; i < imnum; i ++){
 		if (!strcmp(imfile[i], fullname)) {
+			image = imagedata[i];
 			return imdata[i];
 		}
 	}
 	return NULL;
 }
 
-void regist_imdata(fullname, im)
+void regist_imdata(fullname, im, image)
 	char *fullname; 
-	ImlibImage *im;
+	Imlib_Image *im;
+	Image *image;
 {
 	strcpy(imfile[imnum], fullname);	
 	imdata[imnum] = im;
+	imagedata[imnum] = image;
 	imnum ++;
 }
 
 Pixmap pixmap_fromimimage(imimage, width, height)
-	ImlibImage *imimage;
+	Imlib_Image *imimage;
 	int width, height;
 {
 	static Pixmap pixmap;
+#if 0
 	Imlib_render(id, imimage, width, height);
 	pixmap = Imlib_move_image(id, imimage);
+#else
+	imlib_render_pixmaps_for_whole_image_at_size(&pixmap, NULL, width, height);
+#endif
 
 	return pixmap;
 }
@@ -125,8 +173,8 @@ manage_pixmap(pixmap, add, page)
 		ppage[i] = page;
 	} else {
 		for (i = 0; i < MAXPMAP; i ++) {
-			if (ppage[i] == page){
-				Imlib_free_pixmap(id, pmap[i]);
+			if (ppage[i] == page && pmap[i] != 0){
+				imlib_free_pixmap_and_mask(pmap[i]);
 				pmap[i] = 0;
 			}
 		}
