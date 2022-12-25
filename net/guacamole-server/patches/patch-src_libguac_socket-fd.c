$NetBSD: patch-src_libguac_socket-fd.c,v 1.3 2022/12/25 18:39:51 wiz Exp $

Avoid using undefined function on NetBSD.

--- src/libguac/socket-fd.c.orig	2018-12-17 06:47:34.000000000 +0000
+++ src/libguac/socket-fd.c
@@ -431,7 +431,9 @@ guac_socket* guac_socket_open(int fd) {
     socket->data = data;
 
     pthread_mutexattr_init(&lock_attributes);
+#ifndef __NetBSD__
     pthread_mutexattr_setpshared(&lock_attributes, PTHREAD_PROCESS_SHARED);
+#endif
 
     /* Init locks */
     pthread_mutex_init(&(data->socket_lock), &lock_attributes);
