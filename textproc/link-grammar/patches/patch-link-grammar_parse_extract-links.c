$NetBSD: patch-link-grammar_parse_extract-links.c,v 1.1 2023/10/15 06:39:25 ryoon Exp $

--- link-grammar/parse/extract-links.c.orig	2023-03-16 18:49:51.000000000 +0000
+++ link-grammar/parse/extract-links.c
@@ -294,7 +294,7 @@ void free_extractor(extractor_t * pex)
 
 	xfree((void *) pex, sizeof(extractor_t));
 
-#if defined __GNUC__
+#if defined(__GNUC__) && !defined(__NetBSD__)
 	// malloc_trim() is a gnu extension.  An alternative would be
 	// to call madvise(MADV_DONTNEED) but this is more complicated.
 	if (trim) malloc_trim(0);
