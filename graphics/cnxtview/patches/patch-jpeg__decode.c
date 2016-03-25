$NetBSD: patch-jpeg__decode.c,v 1.2 2016/03/25 21:12:57 joerg Exp $

* To match prototype from jpeg>=9 libary

--- jpeg_decode.c.orig	2004-01-13 16:40:32.000000000 +0000
+++ jpeg_decode.c
@@ -82,7 +82,7 @@ term_mem_source (j_decompress_ptr cinfo)
 
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * source_ptr, size_t source_length)
+jpeg_mem_src (j_decompress_ptr cinfo, const unsigned char * source_ptr, unsigned long source_length)
 {
 	mem_src_ptr src;
    
