$NetBSD: patch-src_simage__tiff.c,v 1.1 2024/10/08 20:43:17 rjs Exp $

--- src/simage_tiff.c.orig	2024-09-17 15:21:49.117656332 +0000
+++ src/simage_tiff.c
@@ -85,7 +85,7 @@ tiff_warn(const char * module, const cha
 }
 
 static int
-checkcmap(int n, uint16* r, uint16* g, uint16* b)
+checkcmap(int n, uint16_t * r, uint16_t * g, uint16_t * b)
 {
   while (n-- > 0)
     if (*r++ >= 256 || *g++ >= 256 || *b++ >= 256)
@@ -212,17 +212,17 @@ simage_tiff_load(const char *filename,
                  int *numComponents_ret)
 {
   TIFF *in;
-  uint16 samplesperpixel;
-  uint16 bitspersample;
-  uint16 photometric;
-  uint32 w, h;
-  uint16 config;
-  uint16* red;
-  uint16* green;
-  uint16* blue;
+  uint16_t samplesperpixel;
+  uint16_t bitspersample;
+  uint16_t photometric;
+  uint32_t w, h;
+  uint16_t config;
+  uint16_t * red;
+  uint16_t * green;
+  uint16_t * blue;
   unsigned char *inbuf = NULL;
   tsize_t rowsize;
-  uint32 row;
+  uint32_t row;
   int format;
   unsigned char *buffer;
   int width;
@@ -387,7 +387,7 @@ simage_tiff_load(const char *filename,
       for (row = 0; !tifferror && row < h; row++) {
         int s;
         for (s = 0; s < format; s++) {
-          if (TIFFReadScanline(in, (tdata_t)(inbuf+s*rowsize), (uint32)row, (tsample_t)s) < 0) {
+          if (TIFFReadScanline(in, (tdata_t)(inbuf+s*rowsize), (uint32_t)row, (tsample_t)s) < 0) {
             tifferror = ERR_READ; break;
           }
         }
@@ -427,7 +427,7 @@ simage_tiff_save(const char *filename,
                  int height,
                  int numcomponents)
 {
-  uint16 photometric;
+  uint16_t photometric;
   TIFF * out;
   int y, bytesperrow;
   short config = PLANARCONFIG_CONTIG;
@@ -439,8 +439,8 @@ simage_tiff_save(const char *filename,
     return 0;
   }
 
-  TIFFSetField(out, TIFFTAG_IMAGEWIDTH, (uint32) width);
-  TIFFSetField(out, TIFFTAG_IMAGELENGTH, (uint32) height);
+  TIFFSetField(out, TIFFTAG_IMAGEWIDTH, (uint32_t) width);
+  TIFFSetField(out, TIFFTAG_IMAGELENGTH, (uint32_t) height);
   TIFFSetField(out, TIFFTAG_BITSPERSAMPLE, 8);
   TIFFSetField(out, TIFFTAG_COMPRESSION, compression);
   if (numcomponents <= 2)
@@ -452,12 +452,12 @@ simage_tiff_save(const char *filename,
   TIFFSetField(out, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
   TIFFSetField(out, TIFFTAG_SAMPLESPERPIXEL, numcomponents);
   if (numcomponents == 2 || numcomponents == 4) {
-    uint16 v[1];
+    uint16_t v[1];
     v[0] = EXTRASAMPLE_UNASSALPHA;
     TIFFSetField(out, TIFFTAG_EXTRASAMPLES, 1, v);
   }
-  TIFFSetField(out, TIFFTAG_MINSAMPLEVALUE, (uint16) 0);
-  TIFFSetField(out, TIFFTAG_MAXSAMPLEVALUE, (uint16) 255);
+  TIFFSetField(out, TIFFTAG_MINSAMPLEVALUE, (uint16_t) 0);
+  TIFFSetField(out, TIFFTAG_MAXSAMPLEVALUE, (uint16_t) 255);
   TIFFSetField(out, TIFFTAG_PLANARCONFIG, config);
   /* force 1 row/strip for library limitation */
   TIFFSetField(out, TIFFTAG_ROWSPERSTRIP, 1L);
@@ -479,14 +479,14 @@ simage_tiff_save(const char *filename,
 
 typedef struct {
   TIFF * in;
-  uint16 samplesperpixel;
-  uint16 bitspersample;
-  uint16 photometric;
-  uint32 w, h;
-  uint16 config;
-  uint16 * red;
-  uint16 * green;
-  uint16 * blue;
+  uint16_t samplesperpixel;
+  uint16_t bitspersample;
+  uint16_t photometric;
+  uint32_t w, h;
+  uint16_t config;
+  uint16_t * red;
+  uint16_t * green;
+  uint16_t * blue;
   int format;
   int rowsize;
   unsigned char * inbuf;
@@ -664,7 +664,7 @@ simage_tiff_read_line(void * opendata, i
     case pack(PHOTOMETRIC_RGB, PLANARCONFIG_SEPARATE):
       for (s = 0; s < od->format; s++) {
         if (TIFFReadScanline(od->in, (tdata_t)(od->inbuf+s*od->rowsize),
-                             (uint32)row, (tsample_t)s) < 0) {
+                             (uint32_t)row, (tsample_t)s) < 0) {
           tifferror = ERR_READ; break;
         }
       }
