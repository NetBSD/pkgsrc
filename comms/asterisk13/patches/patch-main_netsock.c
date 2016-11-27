$NetBSD: patch-main_netsock.c,v 1.2 2016/11/27 08:48:19 jnemeth Exp $

--- main/netsock.c.orig	2016-11-23 15:26:01.000000000 +0000
+++ main/netsock.c
@@ -35,5 +35,5 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #if !defined (__linux__) && !defined (__GNU__)
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
