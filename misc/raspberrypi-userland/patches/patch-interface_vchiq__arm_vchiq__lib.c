$NetBSD: patch-interface_vchiq__arm_vchiq__lib.c,v 1.1 2016/11/01 16:45:28 skrll Exp $

--- interface/vchiq_arm/vchiq_lib.c.orig	2016-11-01 11:24:50.000000000 +0000
+++ interface/vchiq_arm/vchiq_lib.c
@@ -1526,7 +1526,7 @@ completion_thread(void *arg)
 
    while (1)
    {
-      int count, i;
+      int ret, i;
 
       while ((unsigned int)args.msgbufcount < vcos_countof(msgbufs))
       {
