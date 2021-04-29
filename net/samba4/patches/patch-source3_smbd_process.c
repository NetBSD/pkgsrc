$NetBSD: patch-source3_smbd_process.c,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- source3/smbd/process.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ source3/smbd/process.c
@@ -3342,6 +3342,7 @@ bool fork_echo_handler(struct smbXsrv_co
 			goto fail;
 		}
 
+		memset(&a, 0, sizeof(pthread_mutexattr_t));
 		res = pthread_mutexattr_init(&a);
 		if (res != 0) {
 			DEBUG(1, ("pthread_mutexattr_init failed: %s\n",
@@ -3369,6 +3370,7 @@ bool fork_echo_handler(struct smbXsrv_co
 			pthread_mutexattr_destroy(&a);
 			goto fail;
 		}
+		memset(xconn->smb1.echo_handler.socket_mutex, 0, sizeof(pthread_mutex_t));
 		res = pthread_mutex_init(xconn->smb1.echo_handler.socket_mutex,
 					 &a);
 		pthread_mutexattr_destroy(&a);
