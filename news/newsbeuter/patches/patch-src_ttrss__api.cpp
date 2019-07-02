$NetBSD: patch-src_ttrss__api.cpp,v 1.1 2019/07/02 07:37:54 nia Exp $

Update for newer json-c API.

https://github.com/json-c/json-c/issues/304

--- src/ttrss_api.cpp.orig	2015-02-19 10:56:59.000000000 +0000
+++ src/ttrss_api.cpp
@@ -113,19 +113,19 @@ struct json_object * ttrss_api::run_op(c
 	LOG(LOG_DEBUG, "ttrss_api::run_op(%s,...): post=%s reply = %s", op.c_str(), req_data.c_str(), result.c_str());
 
 	struct json_object * reply = json_tokener_parse(result.c_str());
-	if (is_error(reply)) {
+	if (reply == NULL) {
 		LOG(LOG_ERROR, "ttrss_api::run_op: reply failed to parse: %s", result.c_str());
 		return NULL;
 	}
 
 	struct json_object * status = json_object_object_get(reply, "status");
-	if (is_error(status)) {
+	if (status == NULL) {
 		LOG(LOG_ERROR, "ttrss_api::run_op: no status code");
 		return NULL;
 	}
 
 	struct json_object * content = json_object_object_get(reply, "content");
-	if (is_error(content)) {
+	if (content == NULL) {
 		LOG(LOG_ERROR, "ttrss_api::run_op: no content part in answer from server");
 		return NULL;
 	}
