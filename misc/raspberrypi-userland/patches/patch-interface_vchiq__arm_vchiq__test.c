$NetBSD: patch-interface_vchiq__arm_vchiq__test.c,v 1.1 2015/01/24 12:54:15 skrll Exp $

--- interface/vchiq_arm/vchiq_test.c.orig	2015-01-18 10:10:36.000000000 +0000
+++ interface/vchiq_arm/vchiq_test.c
@@ -1067,7 +1067,9 @@ do_vchi_ping_test(VCHI_SERVICE_HANDLE_T 
    {
       params->magic = MSG_SYNC;
 
+      vcos_mutex_lock(&g_mutex);
       g_sync_mode = 1;
+      vcos_mutex_unlock(&g_mutex);
 
       start = vcos_getmicrosecs();
       for (i = 0; i < iters; i++)
@@ -1082,7 +1084,9 @@ do_vchi_ping_test(VCHI_SERVICE_HANDLE_T 
 
       vcos_sleep(10);
 
+      vcos_mutex_lock(&g_mutex);
       g_sync_mode = 0;
+      vcos_mutex_unlock(&g_mutex);
    }
 
    while (vchi_msg_dequeue(service, pong_buf, sizeof(pong_buf), &actual, VCHI_FLAGS_NONE) != -1)
