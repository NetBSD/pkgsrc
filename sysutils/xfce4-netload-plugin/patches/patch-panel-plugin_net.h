$NetBSD: patch-panel-plugin_net.h,v 1.1 2015/04/21 08:56:41 jperkin Exp $

Fix DragonFly build.
--- panel-plugin/net.h.orig	2014-11-22 17:11:26.000000000 +0000
+++ panel-plugin/net.h
@@ -69,7 +69,7 @@ typedef struct
 #ifdef __HPUX__
     int             wait_pcks_counter;
     nmapi_logstat*  if_ptr;
-#elif __FreeBSD__ || __DragonFly__ || __FreeBSD_kernel__
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
     int             watchif;
     int             dev_opened;
 #elif __NetBSD__
