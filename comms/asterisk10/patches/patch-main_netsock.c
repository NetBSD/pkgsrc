$NetBSD: patch-main_netsock.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- main/netsock.c.orig	2010-12-10 16:28:14.000000000 +0000
+++ main/netsock.c
@@ -31,5 +31,5 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifndef __linux__ 
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
