$NetBSD: patch-unix_xserver_os_inputthread.c,v 1.1 2021/05/16 21:06:43 wiz Exp $

--- unix/xserver/os/inputthread.c.orig	2021-04-28 14:41:01.046740215 +0000
+++ unix/xserver/os/inputthread.c
@@ -318,7 +317,9 @@ InputThreadDoWork(void *arg)
     sigfillset(&set);
     pthread_sigmask(SIG_BLOCK, &set, NULL);
 
+#ifndef __NetBSD__
     ddxInputThreadInit();
+#endif
 
     inputThreadInfo->running = TRUE;
 
