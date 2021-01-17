$NetBSD: patch-lib_remote_configfileshandler.cpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/remote/configfileshandler.cpp.orig
+++ lib/remote/configfileshandler.cpp
@@ -84,7 +84,7 @@ bool ConfigFilesHandler::HandleRequest(
 		response.result(http::status::ok);
 		response.set(http::field::content_type, "application/octet-stream");
 		response.body() = content;
-		response.set(http::field::content_length, response.body().size());
+		response.content_length(response.body().size());
 	} catch (const std::exception& ex) {
 		HttpUtility::SendJsonError(response, params, 500, "Could not read file.",
 			DiagnosticInformation(ex));
