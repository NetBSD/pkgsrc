$NetBSD: patch-src_libguac_client.c,v 1.1 2022/12/25 18:39:51 wiz Exp $

Avoid using undefined function on NetBSD.

--- src/libguac/client.c.orig	2018-12-16 04:23:01.000000000 +0000
+++ src/libguac/client.c
@@ -171,7 +171,9 @@ guac_client* guac_client_alloc() {
 
     /* Init locks */
     pthread_rwlockattr_init(&lock_attributes);
+#ifndef __NetBSD__
     pthread_rwlockattr_setpshared(&lock_attributes, PTHREAD_PROCESS_SHARED);
+#endif
 
     pthread_rwlock_init(&(client->__users_lock), &lock_attributes);
 
