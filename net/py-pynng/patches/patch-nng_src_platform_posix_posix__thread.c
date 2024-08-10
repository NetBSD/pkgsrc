$NetBSD: patch-nng_src_platform_posix_posix__thread.c,v 1.2 2024/08/10 07:34:38 wiz Exp $

Fix build on NetBSD

--- nng/src/platform/posix/posix_thread.c.orig	2024-01-16 17:27:13.000000000 +0000
+++ nng/src/platform/posix/posix_thread.c
@@ -316,6 +316,12 @@ nni_plat_thr_set_name(nni_plat_thr *thr,
 	} else {
 		pthread_setname_np(thr->tid, "%s", name);
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
