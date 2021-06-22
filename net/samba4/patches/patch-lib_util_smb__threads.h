$NetBSD: patch-lib_util_smb__threads.h,v 1.3 2021/06/22 09:36:41 nia Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- lib/util/smb_threads.h.orig	2020-07-09 09:33:56.000000000 +0000
+++ lib/util/smb_threads.h
@@ -66,6 +66,7 @@ static int smb_create_mutex_pthread(cons
 	if (!pmut) { \
 		return ENOMEM; \
 	} \
+	memset(pmut, 0, sizeof(pthread_mutex_t)); \
 	pthread_mutex_init(pmut, NULL); \
 	*pplock = (void *)pmut; \
 	return 0; \
