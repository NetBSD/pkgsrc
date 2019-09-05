$NetBSD: patch-third__party_socket__wrapper_socket__wrapper.c,v 1.1 2019/09/05 12:39:56 hauke Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure
    
--- third_party/socket_wrapper/socket_wrapper.c.orig	2019-01-15 10:07:01.000000000 +0000
+++ third_party/socket_wrapper/socket_wrapper.c
@@ -1329,6 +1329,7 @@ static int socket_wrapper_init_mutex(pth
 	pthread_mutexattr_t ma;
 	int ret;
 
+	memset(ma, 0, sizeof(pthread_mutexattr_t));
 	ret = pthread_mutexattr_init(&ma);
 	if (ret != 0) {
 		return ret;
@@ -1339,6 +1340,7 @@ static int socket_wrapper_init_mutex(pth
 		goto done;
 	}
 
+	memset(m, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(m, &ma);
 
 done:
