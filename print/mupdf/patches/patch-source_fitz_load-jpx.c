$NetBSD: patch-source_fitz_load-jpx.c,v 1.2 2016/02/04 11:50:24 leot Exp $

Fix build with openjpeg-2.1.
I have misgivings about the code though.

--- source/fitz/load-jpx.c.orig	2015-11-10 16:19:51.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -117,7 +117,8 @@ fz_load_jpx(fz_context *ctx, unsigned ch
 	opj_stream_set_read_function(stream, fz_opj_stream_read);
 	opj_stream_set_skip_function(stream, fz_opj_stream_skip);
 	opj_stream_set_seek_function(stream, fz_opj_stream_seek);
-	opj_stream_set_user_data(stream, &sb);
+	/* XXX: sb is on the stack, so no user data free-er needed; I'm not sure that placing it on the stack will work though? */
+	opj_stream_set_user_data(stream, &sb, NULL);
 	/* Set the length to avoid an assert */
 	opj_stream_set_user_data_length(stream, size);
 
