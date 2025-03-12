$NetBSD: patch-src_common_gres.c,v 1.1 2025/03/12 18:54:23 adam Exp $

qsort_r() is not implemented on NetBSD.

--- src/common/gres.c.orig	2022-05-04 19:32:38.000000000 +0000
+++ src/common/gres.c
@@ -8299,8 +8299,10 @@ extern void gres_plugin_job_core_filter3
 		sufficient_gres = false;
 		for (s = 0; s < sockets; s++)
 			socket_index[s] = s;
+#if !defined(__NetBSD__)
 		qsort_r(socket_index, sockets, sizeof(int),
 			_sort_sockets_by_avail_cores, avail_cores_per_sock);
+#endif
 
 		for (j = 0; j < sockets; j++) {
 			/*
