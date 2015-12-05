$NetBSD: patch-main_netsock.c,v 1.1.1.1 2015/12/05 23:29:10 jnemeth Exp $

--- main/netsock.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/netsock.c
@@ -35,5 +35,5 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifndef __linux__
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
