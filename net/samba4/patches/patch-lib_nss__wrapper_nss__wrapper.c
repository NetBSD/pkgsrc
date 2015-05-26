$NetBSD: patch-lib_nss__wrapper_nss__wrapper.c,v 1.1 2015/05/26 15:11:26 jperkin Exp $

Avoid nss.h on SunOS, incompatible with other nss.h implementations.

--- lib/nss_wrapper/nss_wrapper.c.orig	2014-10-01 09:16:21.000000000 +0000
+++ lib/nss_wrapper/nss_wrapper.c
@@ -68,7 +68,7 @@
 
 #include <dlfcn.h>
 
-#if defined(HAVE_NSS_H)
+#if defined(HAVE_NSS_H) && !defined(__sun)
 /* Linux and BSD */
 #include <nss.h>
 
