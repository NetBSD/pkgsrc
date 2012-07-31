$NetBSD: patch-sapi_fpm_fpm__fpm_sockets.c,v 1.1 2012/07/31 12:23:12 fhajny Exp $

Silly bug. 'sun' is of course taken on SunOS.
--- sapi/fpm/fpm/fpm_sockets.c.orig	2012-07-18 06:19:16.000000000 +0000
+++ sapi/fpm/fpm/fpm_sockets.c
@@ -455,11 +455,11 @@ int fpm_socket_get_listening_queue(int s
 
 #endif
 
-int fpm_socket_unix_test_connect(struct sockaddr_un *sun, size_t socklen) /* {{{ */
+int fpm_socket_unix_test_connect(struct sockaddr_un *fpm_sun, size_t socklen) /* {{{ */
 {
 	int fd;
 
-	if (!sun || sun->sun_family != AF_UNIX) {
+	if (!fpm_sun || fpm_sun->sun_family != AF_UNIX) {
 		return -1;
 	}
 
@@ -467,7 +467,7 @@ int fpm_socket_unix_test_connect(struct
 		return -1;
 	}
 
-	if (connect(fd, (struct sockaddr *)sun, socklen) == -1) {
+	if (connect(fd, (struct sockaddr *)fpm_sun, socklen) == -1) {
 		return -1;
 	}
 
