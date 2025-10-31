$NetBSD: patch-src_utils_os__file.c,v 1.1 2025/10/31 21:46:23 adam Exp $

Fix build on NetBSD.

--- src/utils/os_file.c.orig	2025-10-31 21:19:41.207916708 +0000
+++ src/utils/os_file.c
@@ -1693,6 +1693,9 @@ size_t gf_fread(void *ptr, size_t nbytes
 	return result;
 }
 
+#ifdef __NetBSD__
+#undef gets
+#endif
 GF_EXPORT
 char *gf_fgets(char *ptr, size_t size, FILE *stream)
 {
