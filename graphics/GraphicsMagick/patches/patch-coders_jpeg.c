$NetBSD: patch-coders_jpeg.c,v 1.1 2023/08/02 07:57:36 adam Exp $

Fix for libjpeg-turbo 3.0.0.
https://sourceforge.net/p/graphicsmagick/bugs/711/

--- coders/jpeg.c.orig	2022-12-26 16:56:04.000000000 +0000
+++ coders/jpeg.c
@@ -954,7 +954,7 @@ EstimateJPEGQuality(const struct jpeg_de
     i;
 
   save_quality=0;
-#ifdef D_LOSSLESS_SUPPORTED
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(D_LOSSLESS_SUPPORTED)
   if (image->compression==LosslessJPEGCompression)
     {
       save_quality=100;
@@ -1461,7 +1461,9 @@ static Image *ReadJPEGImage(const ImageI
     }
 #endif
 #if (JPEG_LIB_VERSION >= 61) && defined(D_PROGRESSIVE_SUPPORTED)
-#ifdef D_LOSSLESS_SUPPORTED
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(D_LOSSLESS_SUPPORTED)
+  /* This code is based on a patch to IJG JPEG 6b, or somesuch.  Standard
+     library does not have a 'process' member. */
   image->interlace=
     jpeg_info.process == JPROC_PROGRESSIVE ? LineInterlace : NoInterlace;
   image->compression=jpeg_info.process == JPROC_LOSSLESS ?
@@ -2896,7 +2896,7 @@ static MagickPassFail WriteJPEGImage(con
   if ((image->compression == LosslessJPEGCompression) ||
       (quality > 100))
     {
-#if defined(C_LOSSLESS_SUPPORTED)
+#if !defined(LIBJPEG_TURBO_VERSION_NUMBER) && defined(C_LOSSLESS_SUPPORTED)
       if (quality < 100)
         ThrowException(&image->exception,CoderWarning,
                        LosslessToLossyJPEGConversion,(char *) NULL);
