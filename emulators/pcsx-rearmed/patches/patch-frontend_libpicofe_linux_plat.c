$NetBSD: patch-frontend_libpicofe_linux_plat.c,v 1.1 2024/04/26 09:10:10 nia Exp $

NetBSD support.

--- frontend/libpicofe/linux/plat.c.orig	2024-04-16 09:44:58.820854847 +0000
+++ frontend/libpicofe/linux/plat.c
@@ -223,7 +223,11 @@ void *plat_mremap(void *ptr, size_t olds
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
