$NetBSD: patch-src_libImaging_Jpeg2KDecode.c,v 1.1 2024/02/27 10:00:09 adam Exp $

Fix for OpenJPEG 2.5.1.

--- src/libImaging/Jpeg2KDecode.c.orig	2024-02-27 09:47:51.462363389 +0000
+++ src/libImaging/Jpeg2KDecode.c
@@ -668,10 +668,6 @@ j2k_decode_entry(Imaging im, ImagingCode
     opj_stream_set_read_function(stream, j2k_read);
     opj_stream_set_skip_function(stream, j2k_skip);
 
-    /* OpenJPEG 2.0 doesn't have OPJ_VERSION_MAJOR */
-#ifndef OPJ_VERSION_MAJOR
-    opj_stream_set_user_data(stream, state);
-#else
     opj_stream_set_user_data(stream, state, NULL);
 
     /* Hack: if we don't know the length, the largest file we can
@@ -683,7 +679,6 @@ j2k_decode_entry(Imaging im, ImagingCode
     } else {
         opj_stream_set_user_data_length(stream, context->length);
     }
-#endif
 
     /* Setup decompression context */
     context->error_msg = NULL;
