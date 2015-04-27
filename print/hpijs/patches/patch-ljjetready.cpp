$NetBSD: patch-ljjetready.cpp,v 1.1 2015/04/27 23:52:34 joerg Exp $

--- ljjetready.cpp.orig	2015-04-27 23:38:32.000000000 +0000
+++ ljjetready.cpp
@@ -801,12 +801,8 @@ extern "C"
 {
 void jpeg_finish_compress (j_compress_ptr cinfo);
 JDIMENSION jpeg_write_scanlines (j_compress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION num_lines);
-void jpeg_start_compress(struct jpeg_compress_struct *,unsigned char);
-void jpeg_suppress_tables(struct jpeg_compress_struct *,unsigned char);
-void jpeg_add_quant_table(struct jpeg_compress_struct *,int,unsigned int const *,int,unsigned char);
 void jpeg_default_colorspace(struct jpeg_compress_struct *);
 void jpeg_set_defaults(struct jpeg_compress_struct *);
-void jpeg_CreateCompress(struct jpeg_compress_struct *,int,unsigned int);
 void jpeg_destroy_compress(struct jpeg_compress_struct *);
 void jpeg_buffer_dest (j_compress_ptr cinfo, JOCTET* outbuff, void* flush_output_buffer_callback);
 struct jpeg_error_mgr * jpeg_std_error(struct jpeg_error_mgr * err);
