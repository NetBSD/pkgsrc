$NetBSD: patch-core_http__req.c,v 1.1 2022/12/23 12:40:04 wiz Exp $

core/http_req.c:55:2: error: 'CURLOPT_PROTOCOLS' is deprecated: since 7.85.0. Use CURLOPT_PROTOCOLS_STR

--- core/http_req.c.orig	2020-04-22 16:11:18.000000000 +0000
+++ core/http_req.c
@@ -52,7 +52,7 @@ http_request(const char *url, http_req_t
 	if ((curl = curl_easy_init()) == NULL) {
 		return -1;
 	}
-	curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_HTTPS);
+	curl_easy_setopt(curl, CURLOPT_PROTOCOLS_STR, CURLPROTO_HTTPS);
 	if ((res = curl_easy_setopt(curl, CURLOPT_URL, url)) != CURLE_OK) {
 		app_log(LOG_ERR, "http without TLS is not allowed");
 		goto out;
