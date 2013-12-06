$NetBSD: patch-src_common_xcgroup.h,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/common/xcgroup.h.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/common/xcgroup.h
@@ -49,7 +49,7 @@
 #define XCGROUP_SUCCESS  0
 
 // http://lists.debian.org/debian-boot/2012/04/msg00047.html
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #define	MS_NOSUID	MNT_NOSUID
 #define	MS_NOEXEC	MNT_NOEXEC
 #define	MS_NODEV	0
