$NetBSD: patch-src_filed_bacl__freebsd.h,v 1.1 2020/05/24 01:22:16 joerg Exp $

--- src/filed/bacl_freebsd.h.orig	2020-05-23 22:42:58.371185596 +0000
+++ src/filed/bacl_freebsd.h
@@ -28,7 +28,7 @@
 #ifndef __BACL_FreeBSD_H_
 #define __BACL_FreeBSD_H_
 
-#if defined(HAVE_FREEBSD_OS)
+#if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 #include <sys/types.h>
 
 /* check if ACL support is enabled */
