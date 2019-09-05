$NetBSD: patch-lib_util_smb__threads.h,v 1.1 2019/09/05 12:39:56 hauke Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure
    
--- lib/util/smb_threads.h.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/util/smb_threads.h
@@ -66,6 +66,7 @@ static int smb_create_mutex_pthread(cons
 	if (!pmut) { \
 		return ENOMEM; \
 	} \
+	memset(pmut, 0, sizeof(pthread_mutex_t)); \
 	pthread_mutex_init(pmut, NULL); \
 	*pplock = (void *)pmut; \
 	return 0; \
