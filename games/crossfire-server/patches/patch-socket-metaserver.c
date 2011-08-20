$NetBSD: patch-socket-metaserver.c,v 1.1 2011/08/20 15:32:48 joerg Exp $

--- socket/metaserver.c.orig	2008-02-01 05:56:29.000000000 +0000
+++ socket/metaserver.c
@@ -48,7 +48,6 @@
 
 #ifdef HAVE_CURL_CURL_H
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
