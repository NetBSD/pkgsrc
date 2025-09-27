$NetBSD: patch-src_libjasper_jp2_jp2__cod.h,v 1.1 2025/09/27 15:01:59 tnn Exp $

Arguably jp2_colr_t.iccp should be of type void* since it points to
an opaque ICCP profile and to match usage with jas_malloc, jas_stream_read
and jas_stream_write which all operate on void*.

https://github.com/jasper-software/jasper/issues/406

--- src/libjasper/jp2/jp2_cod.h.orig	2025-09-27 14:50:56.282303343 +0000
+++ src/libjasper/jp2/jp2_cod.h
@@ -177,7 +177,7 @@ typedef struct {
 	uint_fast8_t pri;
 	uint_fast8_t approx;
 	uint_fast32_t csid;
-	uint_fast8_t *iccp;
+	void *iccp;
 	size_t iccplen;
 	/* XXX - Someday we ought to add ICC profile data here. */
 } jp2_colr_t;
