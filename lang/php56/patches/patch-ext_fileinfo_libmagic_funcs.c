$NetBSD: patch-ext_fileinfo_libmagic_funcs.c,v 1.1 2025/07/09 10:22:20 jperkin Exp $

Fix GCC 14 -Werror=implicit-int.

--- ext/fileinfo/libmagic/funcs.c.orig	2025-07-09 10:13:17.906598156 +0000
+++ ext/fileinfo/libmagic/funcs.c
@@ -437,6 +437,7 @@ file_printedlen(const struct magic_set *
 	return ms->o.buf == NULL ? 0 : strlen(ms->o.buf);
 }
 
+int
 file_replace(struct magic_set *ms, const char *pat, const char *rep)
 {
 	zval *patt;
