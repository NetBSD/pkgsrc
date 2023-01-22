$NetBSD: patch-lib_remote_httphandler.cpp,v 1.1 2023/01/22 17:34:20 ryoon Exp $

--- lib/remote/httphandler.cpp.orig	2022-06-29 17:15:18.000000000 +0000
+++ lib/remote/httphandler.cpp
@@ -57,7 +57,7 @@ void HttpHandler::ProcessRequest(
 	Dictionary::Ptr node = m_UrlTree;
 	std::vector<HttpHandler::Ptr> handlers;
 
-	Url::Ptr url = new Url(request.target().to_string());
+	Url::Ptr url = new Url(std::string(request.target()));
 	auto& path (url->GetPath());
 
 	for (std::vector<String>::size_type i = 0; i <= path.size(); i++) {
