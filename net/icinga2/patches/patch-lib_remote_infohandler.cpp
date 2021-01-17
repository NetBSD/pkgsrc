$NetBSD: patch-lib_remote_infohandler.cpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/remote/infohandler.cpp.orig
+++ lib/remote/infohandler.cpp
@@ -92,7 +92,7 @@ bool InfoHandler::HandleRequest(
 
 		body += R"(<p>More information about API requests is available in the <a href="https://icinga.com/docs/icinga2/latest/" target="_blank">documentation</a>.</p></html>)";
 		response.body() = body;
-		response.set(http::field::content_length, response.body().size());
+		response.content_length(response.body().size());
 	}
 
 	return true;
