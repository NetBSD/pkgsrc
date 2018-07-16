$NetBSD: patch-main_netsock.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/netsock.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ main/netsock.c
@@ -32,7 +32,7 @@
 #include "asterisk.h"
 
 #if !defined (__linux__) && !defined (__GNU__)
-#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__GLIBC__)
+#if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__Darwin__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <net/if_dl.h>
 #endif
 #endif
