$NetBSD: patch-lib_perfdata_elasticsearchwriter.cpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/perfdata/elasticsearchwriter.cpp.orig
+++ lib/perfdata/elasticsearchwriter.cpp
@@ -494,7 +494,7 @@ void ElasticsearchWriter::SendRequest(const String& body)
 		request.set(http::field::authorization, "Basic " + Base64::Encode(username + ":" + password));
 
 	request.body() = body;
-	request.set(http::field::content_length, request.body().size());
+	request.content_length(request.body().size());
 
 	/* Don't log the request body to debug log, this is already done above. */
 	Log(LogDebug, "ElasticsearchWriter")
