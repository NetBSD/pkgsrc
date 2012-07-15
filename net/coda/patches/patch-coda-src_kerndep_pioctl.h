$NetBSD: patch-coda-src_kerndep_pioctl.h,v 1.1 2012/07/15 17:39:17 marino Exp $

--- coda-src/kerndep/pioctl.h.orig	2012-07-15 01:56:33.000000000 +0000
+++ coda-src/kerndep/pioctl.h
@@ -81,7 +81,7 @@ int pioctl(const char *path, unsigned lo
 /* unpacking macros */
 #ifndef _IOC_NR
 
-#if defined(__NetBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define _IOC_TYPEMASK	0xff
 #define _IOC_TYPESHIFT	8
 #define _IOC_NRMASK	0xff
