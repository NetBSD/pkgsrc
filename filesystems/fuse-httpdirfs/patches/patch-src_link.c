$NetBSD: patch-src_link.c,v 1.1 2026/05/10 16:32:05 vins Exp $

* Fix attribute warnings when building with curl 8.18.
* Fix signedness mismatch warning on 32bit.

--- src/link.c.orig	2026-05-10 02:41:37.000000000 +0000
+++ src/link.c
@@ -66,14 +66,14 @@ static CURL *Link_to_curl(Link *link)
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
-    ret = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
+    ret = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
     /*
      * for following directories without the '/'
      */
-    ret = curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 2);
+    ret = curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 2L);
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
@@ -81,11 +81,11 @@ static CURL *Link_to_curl(Link *link)
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
-    ret = curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);
+    ret = curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
-    ret = curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 15);
+    ret = curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 15L);
     if (ret) {
         lprintf(error, "%s", curl_easy_strerror(ret));
     }
@@ -117,7 +117,7 @@ static CURL *Link_to_curl(Link *link)
         }
     }
     if (CONFIG.insecure_tls) {
-        ret = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
+        ret = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
         if (ret) {
             lprintf(error, "%s", curl_easy_strerror(ret));
         }
@@ -1054,7 +1054,7 @@ static CURL *Link_download_curl_setup(
     size_t end = start + req_size - 1;
 
     char range_str[64];
-    snprintf(range_str, sizeof(range_str), "%lu-%lu", start, end);
+    snprintf(range_str, sizeof(range_str), "%zu-%zu", start, end);
     lprintf(debug, "%s: %s\n", link->linkname, range_str);
 
     CURL *curl = Link_to_curl(link);
