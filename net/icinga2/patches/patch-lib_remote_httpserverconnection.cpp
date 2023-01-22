$NetBSD: patch-lib_remote_httpserverconnection.cpp,v 1.3 2023/01/22 17:34:20 ryoon Exp $

--- lib/remote/httpserverconnection.cpp.orig	2022-06-29 17:15:18.000000000 +0000
+++ lib/remote/httpserverconnection.cpp
@@ -32,7 +32,7 @@
 
 using namespace icinga;
 
-auto const l_ServerHeader ("Icinga/" + Application::GetAppVersion());
+auto const l_ServerHeader (("Icinga/" + Application::GetAppVersion()).CStr());
 
 HttpServerConnection::HttpServerConnection(const String& identity, bool authenticated, const Shared<AsioTlsStream>::Ptr& stream)
 	: HttpServerConnection(identity, authenticated, stream, IoEngine::Get().GetIoContext())
@@ -246,7 +246,7 @@ bool HandleAccessControl(
 			if (!allowedOrigins.empty()) {
 				auto& origin (request[http::field::origin]);
 
-				if (allowedOrigins.find(origin.to_string()) != allowedOrigins.end()) {
+				if (allowedOrigins.find(std::string(origin)) != allowedOrigins.end()) {
 					response.set(http::field::access_control_allow_origin, origin);
 				}
 
@@ -536,7 +536,7 @@ void HttpServerConnection::ProcessMessag
 			if (!authenticatedUser) {
 				CpuBoundWork fetchingAuthenticatedUser (yc);
 
-				authenticatedUser = ApiUser::GetByAuthHeader(request[http::field::authorization].to_string());
+				authenticatedUser = ApiUser::GetByAuthHeader(std::string(request[http::field::authorization]));
 			}
 
 			Log logMsg (LogInformation, "HttpServerConnection");
