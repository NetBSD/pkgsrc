$NetBSD: patch-source_fitz_load-jpx.c,v 1.3 2016/07/15 12:32:33 leot Exp $

 o Restrict OPJ_STATIC to Windows (avoid linking errors due to hidden symbols)
 o Fix build with openjpeg-2.1.
   I have misgivings about the code though.

--- source/fitz/load-jpx.c.orig	2016-04-21 11:14:32.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -3,7 +3,9 @@
 /* Without the definition of OPJ_STATIC, compilation fails on windows
  * due to the use of __stdcall. We believe it is required on some
  * linux toolchains too. */
+#ifdef _WIN32
 #define OPJ_STATIC
+#endif
 #ifndef _MSC_VER
 #define OPJ_HAVE_STDINT_H
 #endif
@@ -117,7 +119,8 @@ fz_load_jpx(fz_context *ctx, unsigned ch
 	opj_stream_set_read_function(stream, fz_opj_stream_read);
 	opj_stream_set_skip_function(stream, fz_opj_stream_skip);
 	opj_stream_set_seek_function(stream, fz_opj_stream_seek);
-	opj_stream_set_user_data(stream, &sb);
+	/* XXX: sb is on the stack, so no user data free-er needed; I'm not sure that placing it on the stack will work though? */
+	opj_stream_set_user_data(stream, &sb, NULL);
 	/* Set the length to avoid an assert */
 	opj_stream_set_user_data_length(stream, size);
 
