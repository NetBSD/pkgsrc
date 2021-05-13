$NetBSD: patch-nng_src_platform_posix_posix__thread.c,v 1.1 2021/05/13 19:35:54 khorben Exp $

Fix build on NetBSD

--- nng/src/platform/posix/posix_thread.c.orig	2020-08-27 02:35:02.000000000 +0000
+++ nng/src/platform/posix/posix_thread.c
@@ -268,6 +268,12 @@ nni_plat_thr_set_name(nni_plat_thr *thr,
 	if ((thr == NULL) || (pthread_self() == thr->tid)) {
         	pthread_setname_np(name);
 	}
+#elif defined(__NetBSD__)
+	if (thr == NULL) {
+		pthread_setname_np(pthread_self(), "%s", name);
+	} else {
+		pthread_setname_np(thr->tid, "%s", name);
+	}
 #else
 	if (thr == NULL) {
                 pthread_setname_np(pthread_self(), name);
