$NetBSD: patch-platform_libpicofe_linux_plat.c,v 1.1 2024/04/26 09:04:31 nia Exp $

NetBSD support.

--- platform/libpicofe/linux/plat.c.orig	2024-04-16 19:15:52.544337311 +0000
+++ platform/libpicofe/linux/plat.c
@@ -215,7 +215,11 @@ void *plat_mremap(void *ptr, size_t olds
 {
 	void *ret;
 
+#ifdef __NetBSD__
+	ret = mremap(ptr, oldsize, NULL, newsize, 0);
+#else
 	ret = mremap(ptr, oldsize, newsize, MREMAP_MAYMOVE);
+#endif
 	if (ret == MAP_FAILED) {
 		fprintf(stderr, "mremap %p %zd %zd: ",
 			ptr, oldsize, newsize);
