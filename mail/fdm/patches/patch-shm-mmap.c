$NetBSD: patch-shm-mmap.c,v 1.1 2019/03/18 10:53:41 leot Exp $

Adjust mremap(2) usage for NetBSD.

--- shm-mmap.c.orig	2019-02-12 22:08:26.000000000 +0000
+++ shm-mmap.c
@@ -218,7 +218,11 @@ shm_resize(struct shm *shm, size_t nmemb
 		return (NULL);
 
 #ifdef HAVE_MREMAP
+#if defined(__NetBSD__)
+	shm->data = mremap(shm->data, shm->size, NULL, newsize, 0);
+#else
 	shm->data = mremap(shm->data, shm->size, newsize, MREMAP_MAYMOVE);
+#endif
 #else
 	shm->data = mmap(NULL, newsize, SHM_PROT, SHM_FLAGS, shm->fd, 0);
 #endif
