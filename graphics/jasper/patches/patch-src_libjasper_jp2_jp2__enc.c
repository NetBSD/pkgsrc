$NetBSD: patch-src_libjasper_jp2_jp2__enc.c,v 1.3 2017/03/05 12:49:52 wiz Exp $

Replace an sprintf() with snprintf().

--- src/libjasper/jp2/jp2_enc.c.orig	2017-03-02 18:03:10.000000000 +0000
+++ src/libjasper/jp2/jp2_enc.c
@@ -385,8 +385,9 @@ int jp2_encode(jas_image_t *image, jas_s
 	/* Output the JPEG-2000 code stream. */
 
 	overhead = jas_stream_getrwcount(out);
-	sprintf(buf, "%s\n_jp2overhead=%lu\n", (optstr ? optstr : ""),
-	  (unsigned long) overhead);
+	snprintf(buf, sizeof buf, "%s\n_jp2overhead=%lu\n",
+		 (optstr ? optstr : ""),
+		 (unsigned long) overhead);
 
 	if (jpc_encode(image, out, buf)) {
 		jas_eprintf("jpc_encode failed\n");
