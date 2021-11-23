$NetBSD: patch-camlibs_jl2005c_jpeg__memsrcdest.h,v 1.2 2021/11/23 14:28:34 ryoon Exp $

Fix build with jpeg-9b.

--- camlibs/jl2005c/jpeg_memsrcdest.h.orig	2019-02-05 07:18:05.000000000 +0000
+++ camlibs/jl2005c/jpeg_memsrcdest.h
@@ -3,7 +3,7 @@
 #if JPEG_LIB_VERSION < 80 && !defined(MEM_SRCDST_SUPPORTED)
 
 void
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
+jpeg_mem_src (j_decompress_ptr cinfo, const unsigned char * buffer,
 	unsigned long bufsize);
 
 void
