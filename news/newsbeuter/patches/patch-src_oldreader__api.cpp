$NetBSD: patch-src_oldreader__api.cpp,v 1.1.2.2 2019/07/02 13:15:50 bsiegert Exp $

Update for newer json-c API.

https://github.com/json-c/json-c/issues/304

--- src/oldreader_api.cpp.orig	2015-02-19 10:56:59.000000000 +0000
+++ src/oldreader_api.cpp
@@ -134,7 +134,7 @@ std::vector<tagged_feedurl> oldreader_ap
 	// TODO: parse result
 
 	struct json_object * reply = json_tokener_parse(result.c_str());
-	if (is_error(reply)) {
+	if (reply == NULL) {
 		LOG(LOG_ERROR, "oldreader_api::get_subscribed_urls: failed to parse response as JSON.");
 		return urls;
 	}
