$NetBSD: patch-coda-src_kerndep_pioctl.h,v 1.3 2015/01/27 15:21:52 hauke Exp $

SunOS wants missing _IOC* defines, too.
    
--- coda-src/kerndep/pioctl.h.orig	2006-11-03 15:58:08.000000000 +0000
+++ coda-src/kerndep/pioctl.h
@@ -81,7 +81,7 @@ int pioctl(const char *path, unsigned lo
 /* unpacking macros */
 #ifndef _IOC_NR
 
-#if defined(__NetBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || (defined (__sun) && defined(__SVR4))
 #define _IOC_TYPEMASK	0xff
 #define _IOC_TYPESHIFT	8
 #define _IOC_NRMASK	0xff
