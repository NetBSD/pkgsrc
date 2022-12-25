$NetBSD: patch-src_libguac_socket-broadcast.c,v 1.1 2022/12/25 18:39:51 wiz Exp $

Avoid using undefined function on NetBSD.

--- src/libguac/socket-broadcast.c.orig	2018-11-21 09:00:59.000000000 +0000
+++ src/libguac/socket-broadcast.c
@@ -357,7 +357,9 @@ guac_socket* guac_socket_broadcast(guac_
     socket->data = data;
 
     pthread_mutexattr_init(&lock_attributes);
+#ifndef __NetBSD__
     pthread_mutexattr_setpshared(&lock_attributes, PTHREAD_PROCESS_SHARED);
+#endif
 
     /* Init lock */
     pthread_mutex_init(&(data->socket_lock), &lock_attributes);
