$NetBSD: patch-libpcsxcore_cdriso.c,v 1.1 2017/02/17 17:02:01 joerg Exp $

--- libpcsxcore/cdriso.c.orig	2017-02-17 14:01:16.071768567 +0000
+++ libpcsxcore/cdriso.c
@@ -1082,7 +1082,7 @@ static int cdread_sub_mixed(FILE *f, uns
 	return ret;
 }
 
-static int uncompress2(void *out, unsigned long *out_size, void *in, unsigned long in_size)
+static int my_uncompress2(void *out, unsigned long *out_size, void *in, unsigned long in_size)
 {
 	static z_stream z;
 	int ret = 0;
@@ -1161,7 +1161,7 @@ static int cdread_compressed(FILE *f, un
 	if (is_compressed) {
 		cdbuffer_size_expect = sizeof(compr_img->buff_raw[0]) << compr_img->block_shift;
 		cdbuffer_size = cdbuffer_size_expect;
-		ret = uncompress2(compr_img->buff_raw[0], &cdbuffer_size, compr_img->buff_compressed, size);
+		ret = my_uncompress2(compr_img->buff_raw[0], &cdbuffer_size, compr_img->buff_compressed, size);
 		if (ret != 0) {
 			SysPrintf("uncompress failed with %d for block %d, sector %d\n",
 					ret, block, sector);
