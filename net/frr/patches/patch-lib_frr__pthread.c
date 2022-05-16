$NetBSD: patch-lib_frr__pthread.c,v 1.1 2022/05/16 11:54:20 kardel Exp $

	avoid tripping over NULL pointer

--- lib/frr_pthread.c.orig	2022-03-13 15:59:48.000000000 +0000
+++ lib/frr_pthread.c
@@ -141,7 +141,7 @@ int frr_pthread_set_name(struct frr_pthr
 # ifdef GNU_LINUX
 	ret = pthread_setname_np(fpt->thread, fpt->os_name);
 # elif defined(__NetBSD__)
-	ret = pthread_setname_np(fpt->thread, fpt->os_name, NULL);
+	ret = pthread_setname_np(fpt->thread, fpt->os_name ? fpt->os_name : "-n/a-", NULL);
 # endif
 #elif defined(HAVE_PTHREAD_SET_NAME_NP)
 	pthread_set_name_np(fpt->thread, fpt->os_name);
