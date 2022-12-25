$NetBSD: patch-src_core_ipp__cache.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/ipp_cache.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/ipp_cache.c
@@ -452,7 +452,7 @@ ipp_cache_parse(ipp_cache_t *ic, FILE *f
 	bit_array_init(tag_used, NUM_IPP_CACHE_TAGS);
 	bit_array_clear_range(tag_used, 0, NUM_IPP_CACHE_TAGS - 1U);
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const char *tag_name, *value;
 		char *sp;
 		bool damaged;
