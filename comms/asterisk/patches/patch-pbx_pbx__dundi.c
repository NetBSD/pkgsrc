$NetBSD: patch-pbx_pbx__dundi.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- pbx/pbx_dundi.c.orig	2012-09-06 02:50:34.000000000 +0000
+++ pbx/pbx_dundi.c
@@ -38,7 +38,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <pthread.h>
 #include <net/if.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__DragonFly__)
 #include <net/if_dl.h>
 #include <ifaddrs.h>
 #include <signal.h>
