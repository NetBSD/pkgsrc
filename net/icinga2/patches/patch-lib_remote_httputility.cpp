$NetBSD: patch-lib_remote_httputility.cpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/remote/httputility.cpp.orig
+++ lib/remote/httputility.cpp
@@ -58,7 +58,7 @@ void HttpUtility::SendJsonBody(boost::beast::http::response<boost::beast::http::
 
 	response.set(http::field::content_type, "application/json");
 	response.body() = JsonEncode(val, params && GetLastParameter(params, "pretty"));
-	response.set(http::field::content_length, response.body().size());
+	response.content_length(response.body().size());
 }
 
 void HttpUtility::SendJsonError(boost::beast::http::response<boost::beast::http::string_body>& response,
