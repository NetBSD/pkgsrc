$NetBSD: patch-src_libImaging_Jpeg2KEncode.c,v 1.1 2024/02/27 10:00:09 adam Exp $

Fix for OpenJPEG 2.5.1.

--- src/libImaging/Jpeg2KEncode.c.orig	2024-02-27 09:53:26.334381456 +0000
+++ src/libImaging/Jpeg2KEncode.c
@@ -295,12 +295,7 @@ j2k_encode_entry(Imaging im, ImagingCode
     opj_stream_set_skip_function(stream, j2k_skip);
     opj_stream_set_seek_function(stream, j2k_seek);
 
-    /* OpenJPEG 2.0 doesn't have OPJ_VERSION_MAJOR */
-#ifndef OPJ_VERSION_MAJOR
-    opj_stream_set_user_data(stream, state);
-#else
     opj_stream_set_user_data(stream, state, NULL);
-#endif
 
     /* Setup an opj_image */
     if (strcmp(im->mode, "L") == 0) {
