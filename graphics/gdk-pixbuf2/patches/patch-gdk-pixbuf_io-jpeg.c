$NetBSD: patch-gdk-pixbuf_io-jpeg.c,v 1.1.2.2 2025/08/04 00:36:09 maya Exp $

From 4af78023ce7d3b5e3cec422a59bb4f48fa4f5886 Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Fri, 11 Jul 2025 11:02:05 -0400
Subject: [PATCH] jpeg: Be more careful with chunked icc data

We we inadvertendly trusting the sequence numbers not to lie.
If they do we would report a larger data size than we actually
allocated, leading to out of bounds memory access in base64
encoding later on.

This has been assigned CVE-2025-7345.

Fixes: #249

--- gdk-pixbuf/io-jpeg.c.orig	2024-05-15 02:15:41.000000000 +0000
+++ gdk-pixbuf/io-jpeg.c
@@ -356,6 +356,7 @@ jpeg_parse_exif_app2_segment (JpegExifCo
 		context->icc_profile = g_new (gchar, chunk_size);
 		/* copy the segment data to the profile space */
 		memcpy (context->icc_profile, marker->data + 14, chunk_size);
+                ret = TRUE;
 		goto out;
 	}
 
@@ -377,12 +378,15 @@ jpeg_parse_exif_app2_segment (JpegExifCo
 	/* copy the segment data to the profile space */
 	memcpy (context->icc_profile + offset, marker->data + 14, chunk_size);
 
-	/* it's now this big plus the new data we've just copied */
-	context->icc_profile_size += chunk_size;
+        context->icc_profile_size = MAX (context->icc_profile_size, offset + chunk_size);
 
 	/* success */
 	ret = TRUE;
 out:
+        if (!ret) {
+                g_free (context->icc_profile);
+                context->icc_profile = NULL;
+        }
 	return ret;
 }
 
