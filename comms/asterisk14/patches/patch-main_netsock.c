$NetBSD: patch-main_netsock.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- main/netsock.c.orig	2016-09-30 20:36:17.000000000 +0000
+++ main/netsock.c
@@ -34,7 +34,7 @@
 ASTERISK_REGISTER_FILE()
 
 #ifndef __linux__
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
 #endif
