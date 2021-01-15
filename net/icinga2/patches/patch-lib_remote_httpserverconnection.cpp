$NetBSD: patch-lib_remote_httpserverconnection.cpp,v 1.1 2021/01/15 00:37:17 wiz Exp $

Support Boost 1.74 when setting HTTP headers

Upstream Issue #8185, Pull Request #8575, commit 339b37a985b5f67ce5f0d2e02211d2c5b98a5d45

--- lib/remote/httpserverconnection.cpp.orig	2020-08-03 15:43:47.000000000 +0200
+++ lib/remote/httpserverconnection.cpp	2021-01-14 19:30:36.695215485 +0100
@@ -186,7 +186,7 @@
 		} else {
 			response.set(http::field::content_type, "text/html");
 			response.body() = String("<h1>Bad Request</h1><p><pre>") + errorMsg + "</pre></p>";
-			response.set(http::field::content_length, response.body().size());
+			response.content_length(response.body().size());
 		}
 
 		response.set(http::field::connection, "close");
@@ -259,7 +259,7 @@
 					response.set(http::field::access_control_allow_methods, "GET, POST, PUT, DELETE");
 					response.set(http::field::access_control_allow_headers, "Authorization, X-HTTP-Method-Override");
 					response.body() = "Preflight OK";
-					response.set(http::field::content_length, response.body().size());
+					response.content_length(response.body().size());
 					response.set(http::field::connection, "close");
 
 					boost::system::error_code ec;
@@ -290,7 +290,7 @@
 		response.result(http::status::bad_request);
 		response.set(http::field::content_type, "text/html");
 		response.body() = "<h1>Accept header is missing or not set to 'application/json'.</h1>";
-		response.set(http::field::content_length, response.body().size());
+		response.content_length(response.body().size());
 		response.set(http::field::connection, "close");
 
 		boost::system::error_code ec;
@@ -331,7 +331,7 @@
 		} else {
 			response.set(http::field::content_type, "text/html");
 			response.body() = "<h1>Unauthorized. Please check your user credentials.</h1>";
-			response.set(http::field::content_length, response.body().size());
+			response.content_length(response.body().size());
 		}
 
 		boost::system::error_code ec;
@@ -423,7 +423,7 @@
 		} else {
 			response.set(http::field::content_type, "text/html");
 			response.body() = String("<h1>Bad Request</h1><p><pre>") + ec.message() + "</pre></p>";
-			response.set(http::field::content_length, response.body().size());
+			response.content_length(response.body().size());
 		}
 
 		response.set(http::field::connection, "close");
