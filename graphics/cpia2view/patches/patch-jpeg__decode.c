$NetBSD: patch-jpeg__decode.c,v 1.1 2014/02/10 11:43:09 obache Exp $

* To match prototype from jpeg>=8 library.

--- jpeg_decode.c.orig	2014-02-10 11:34:47.000000000 +0000
+++ jpeg_decode.c
@@ -82,7 +82,7 @@ term_mem_source (j_decompress_ptr cinfo)
 
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * source_ptr, size_t source_length)
+jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * source_ptr, unsigned long source_length)
 {
 	mem_src_ptr src;
    
