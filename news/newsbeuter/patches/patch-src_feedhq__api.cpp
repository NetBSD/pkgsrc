$NetBSD: patch-src_feedhq__api.cpp,v 1.1 2019/07/02 07:37:54 nia Exp $

Update for newer json-c API.

https://github.com/json-c/json-c/issues/304

--- src/feedhq_api.cpp.orig	2015-02-19 10:56:59.000000000 +0000
+++ src/feedhq_api.cpp
@@ -132,7 +132,7 @@ std::vector<tagged_feedurl> feedhq_api::
 	// TODO: parse result
 
 	struct json_object * reply = json_tokener_parse(result.c_str());
-	if (is_error(reply)) {
+	if (reply == NULL) {
 		LOG(LOG_ERROR, "feedhq_api::get_subscribed_urls: failed to parse response as JSON.");
 		return urls;
 	}
