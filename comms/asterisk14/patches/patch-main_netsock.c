$NetBSD: patch-main_netsock.c,v 1.2 2016/11/27 22:55:51 jnemeth Exp $

--- main/netsock.c.orig	2016-11-23 15:47:57.000000000 +0000
+++ main/netsock.c
@@ -34,7 +34,7 @@
 ASTERISK_REGISTER_FILE()
 
 #if !defined (__linux__) && !defined (__GNU__)
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
 #endif
