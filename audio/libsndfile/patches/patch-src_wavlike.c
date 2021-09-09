$NetBSD: patch-src_wavlike.c,v 1.1 2021/09/09 12:03:10 nia Exp $

[PATCH] wavlike: Fix incorrect size check

The SF_CART_INFO_16K struct has an additional 4 byte field to hold
the size of 'tag_text' which the file header doesn't, so don't
include it as part of the check when looking for the max length.

https://bugs.chromium.org/p/oss-fuzz/issues/detail?id=26026
https://github.com/libsndfile/libsndfile/pull/713

--- src/wavlike.c.orig	2021-01-23 16:12:45.000000000 +0000
+++ src/wavlike.c
@@ -830,7 +830,11 @@ wavlike_read_cart_chunk (SF_PRIVATE *psf
 		return 0 ;
 		} ;
 
-	if (chunksize >= sizeof (SF_CART_INFO_16K))
+	/*
+	**	SF_CART_INFO_16K has an extra field 'tag_text_size' that isn't part
+	**	of the chunk, so don't include it in the size check.
+	*/
+	if (chunksize >= sizeof (SF_CART_INFO_16K) - 4)
 	{	psf_log_printf (psf, "cart : %u too big to be handled\n", chunksize) ;
 		psf_binheader_readf (psf, "j", chunksize) ;
 		return 0 ;
