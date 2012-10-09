$NetBSD: patch-main_netsock.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- main/netsock.c.orig	2012-06-15 16:07:08.000000000 +0000
+++ main/netsock.c
@@ -35,5 +35,5 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifndef __linux__ 
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
