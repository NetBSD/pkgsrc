$NetBSD: patch-src_libjasper_jp2_jp2__enc.c,v 1.2 2016/12/16 09:44:44 he Exp $

Replace an sprintf() with snprintf().

--- src/libjasper/jp2/jp2_enc.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/jp2/jp2_enc.c
@@ -343,8 +343,9 @@ int jp2_encode(jas_image_t *image, jas_s
 	/* Output the JPEG-2000 code stream. */
 
 	overhead = jas_stream_getrwcount(out);
-	sprintf(buf, "%s\n_jp2overhead=%lu\n", (optstr ? optstr : ""),
-	  (unsigned long) overhead);
+	snprintf(buf, sizeof buf, "%s\n_jp2overhead=%lu\n",
+		 (optstr ? optstr : ""),
+		 (unsigned long) overhead);
 
 	if (jpc_encode(image, out, buf)) {
 		goto error;
