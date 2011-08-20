$NetBSD: patch-common-metaserver.c,v 1.1 2011/08/20 15:31:33 joerg Exp $

--- common/metaserver.c.orig	2011-08-20 13:33:08.000000000 +0000
+++ common/metaserver.c
@@ -47,7 +47,6 @@ const char *rcsid_common_metaserver_c =
 
 #ifdef HAVE_CURL_CURL_H
 #include <curl/curl.h>
-#include <curl/types.h>
 #include <curl/easy.h>
 #endif
 
