$NetBSD: patch-nsswitch_stress-nss-libwbclient.c,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- nsswitch/stress-nss-libwbclient.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ nsswitch/stress-nss-libwbclient.c
@@ -118,6 +118,7 @@ int main(int argc, char *argv[])
 
 	state.username = argv[1];
 	state.timeout = time(NULL) + RUNTIME;
+	memset(&state.lock, 0, sizeof(pthread_mutex_t));
 	rc = pthread_mutex_init(&state.lock, NULL);
 	if (rc != 0) {
 		fprintf(stderr,
