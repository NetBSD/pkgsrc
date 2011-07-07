$NetBSD: patch-src_xitk_download.c,v 1.1 2011/07/07 11:46:31 obache Exp $

* not to include deprecated header file of curl.

--- src/xitk/download.c.orig	2009-12-19 00:34:22.000000000 +0000
+++ src/xitk/download.c
@@ -28,7 +28,6 @@
 
 #ifdef HAVE_CURL
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
