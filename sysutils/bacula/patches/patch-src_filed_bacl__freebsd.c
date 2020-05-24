$NetBSD: patch-src_filed_bacl__freebsd.c,v 1.1 2020/05/24 01:22:16 joerg Exp $

--- src/filed/bacl_freebsd.c.orig	2020-05-23 22:41:29.838112856 +0000
+++ src/filed/bacl_freebsd.c
@@ -29,7 +29,7 @@
 #include "filed.h"
 #include "bacl_freebsd.h"
 
-#if defined(HAVE_FREEBSD_OS)
+#if defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
 
 /* check if ACL support is enabled */
 #if defined(HAVE_ACL)
