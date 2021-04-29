$NetBSD: patch-lib_util_smb__threads.h,v 1.2 2021/04/29 15:21:16 taca Exp $

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
