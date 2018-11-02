$NetBSD: patch-src_low-level_feed_newsfeed.c,v 1.1 2018/11/02 09:32:02 jperkin Exp $

Fix build against newer curl API.

--- src/low-level/feed/newsfeed.c.orig	2017-05-08 03:27:35.000000000 +0000
+++ src/low-level/feed/newsfeed.c
@@ -530,7 +530,6 @@ static int curl_error_convert(int curl_r
     return NEWSFEED_ERROR_STREAM;
     
   case CURLE_SSL_CONNECT_ERROR:
-  case CURLE_SSL_PEER_CERTIFICATE:
   case CURLE_SSL_ENGINE_NOTFOUND:
   case CURLE_SSL_ENGINE_SETFAILED:
   case CURLE_SSL_CERTPROBLEM:
