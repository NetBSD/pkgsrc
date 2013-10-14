$NetBSD: patch-src_zlib.c,v 1.1 2013/10/14 06:51:02 adam Exp $

--- src/zlib.c.orig	2013-10-01 10:42:54.000000000 +0000
+++ src/zlib.c
@@ -229,7 +229,7 @@ compress_buffer_input (void *closure, ch
 	   would fetch all the available bytes, and at least one byte.  */
 
 	status = (*cb->buf->input) (cb->buf->closure, bd->text,
-				    need, BUFFER_DATA_SIZE, &nread);
+				    need ? 1 : 0, BUFFER_DATA_SIZE, &nread);
 
 	if (status == -2)
 	    /* Don't try to recover from memory allcoation errors.  */
