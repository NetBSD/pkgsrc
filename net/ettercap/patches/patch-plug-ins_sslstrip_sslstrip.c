$NetBSD: patch-plug-ins_sslstrip_sslstrip.c,v 1.1 2023/04/13 12:38:53 wiz Exp $

Fix build with curl 8.

--- plug-ins/sslstrip/sslstrip.c.orig	2020-08-01 14:32:06.000000000 +0000
+++ plug-ins/sslstrip/sslstrip.c
@@ -53,7 +53,7 @@
 
 #include <curl/curl.h>
 
-#if (LIBCURL_VERSION_MAJOR < 7) || (LIBCURL_VERSION_MINOR < 26)
+#if (LIBCURL_VERSION_MAJOR < 7) || (LIBCURL_VERSION_MAJOR == 7 && LIBCURL_VERSION_MINOR < 26)
 #error libcurl 7.26.0 or up is needed
 #endif
 
