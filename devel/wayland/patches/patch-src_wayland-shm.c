$NetBSD: patch-src_wayland-shm.c,v 1.3 2020/01/05 19:30:48 nia Exp $

NetBSD support

--- src/wayland-shm.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/wayland-shm.c
@@ -84,7 +84,11 @@ shm_pool_finish_resize(struct wl_shm_poo
 	if (pool->size == pool->new_size)
 		return;
 
+#ifdef __NetBSD__
+	data = mremap(pool->data, pool->size, NULL, pool->new_size, 0);
+#else
 	data = mremap(pool->data, pool->size, pool->new_size, MREMAP_MAYMOVE);
+#endif
 	if (data == MAP_FAILED) {
 		wl_resource_post_error(pool->resource,
 				       WL_SHM_ERROR_INVALID_FD,
