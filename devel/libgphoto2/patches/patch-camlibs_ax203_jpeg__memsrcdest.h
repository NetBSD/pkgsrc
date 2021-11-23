$NetBSD: patch-camlibs_ax203_jpeg__memsrcdest.h,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Fix build with jpeg-9b.

--- camlibs/ax203/jpeg_memsrcdest.h.orig	2020-08-31 10:07:48.000000000 +0000
+++ camlibs/ax203/jpeg_memsrcdest.h
@@ -3,7 +3,7 @@
 #if JPEG_LIB_VERSION < 80 && !defined(MEM_SRCDST_SUPPORTED)
 
 void
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
+jpeg_mem_src (j_decompress_ptr cinfo, const unsigned char * buffer,
 	unsigned long bufsize);
 
 void
