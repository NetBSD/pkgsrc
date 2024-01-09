$NetBSD: patch-lib_frr__pthread.c,v 1.2 2024/01/09 20:17:41 chopps Exp $

	avoid tripping over NULL pointer

--- lib/frr_pthread.c.orig	2023-11-27 13:45:33.000000000 +0000
+++ lib/frr_pthread.c
@@ -128,7 +128,7 @@ int frr_pthread_set_name(struct frr_pthr
 # ifdef GNU_LINUX
 	ret = pthread_setname_np(fpt->thread, fpt->os_name);
 # elif defined(__NetBSD__)
-	ret = pthread_setname_np(fpt->thread, fpt->os_name, NULL);
+	ret = pthread_setname_np(fpt->thread, fpt->os_name ? fpt->os_name : "-n/a-", NULL);
 # endif
 #elif defined(HAVE_PTHREAD_SET_NAME_NP)
 	pthread_set_name_np(fpt->thread, fpt->os_name);
