$NetBSD: patch-pbx_pbx__dundi.c,v 1.1 2023/12/10 06:40:20 ryoon Exp $

--- pbx/pbx_dundi.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ pbx/pbx_dundi.c
@@ -47,7 +47,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <pthread.h>
 #include <net/if.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__DragonFly__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #include <signal.h>
