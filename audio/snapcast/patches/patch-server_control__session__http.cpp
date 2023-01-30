$NetBSD: patch-server_control__session__http.cpp,v 1.1 2023/01/30 10:41:57 wiz Exp $

Build fix for boost 1.81.0
https://github.com/badaix/snapcast/commit/853c3f622ff2262b56681ee04dd20b4266c72493

--- server/control_session_http.cpp.orig	2021-12-22 17:40:36.000000000 +0000
+++ server/control_session_http.cpp
@@ -127,8 +127,8 @@ boost::beast::string_view mime_type(boos
 std::string path_cat(boost::beast::string_view base, boost::beast::string_view path)
 {
     if (base.empty())
-        return path.to_string();
-    std::string result = base.to_string();
+        return static_cast<std::string>(path);
+    std::string result = static_cast<std::string>(base);
     char constexpr path_separator = '/';
     if (result.back() == path_separator)
         result.resize(result.size() - 1);
@@ -171,7 +171,7 @@ void ControlSessionHttp::handle_request(
         res.set(http::field::server, HTTP_SERVER_NAME);
         res.set(http::field::content_type, "text/html");
         res.keep_alive(req.keep_alive());
-        res.body() = why.to_string();
+        res.body() = static_cast<std::string>(why);
         res.prepare_payload();
         return res;
     };
@@ -182,7 +182,7 @@ void ControlSessionHttp::handle_request(
         res.set(http::field::server, HTTP_SERVER_NAME);
         res.set(http::field::content_type, "text/html");
         res.keep_alive(req.keep_alive());
-        res.body() = "The resource '" + target.to_string() + "' was not found.";
+        res.body() = "The resource '" + static_cast<std::string>(target) + "' was not found.";
         res.prepare_payload();
         return res;
     };
@@ -204,7 +204,7 @@ void ControlSessionHttp::handle_request(
         res.set(http::field::server, HTTP_SERVER_NAME);
         res.set(http::field::content_type, "text/html");
         res.keep_alive(req.keep_alive());
-        res.body() = "An error occurred: '" + what.to_string() + "'";
+        res.body() = "An error occurred: '" + static_cast<std::string>(what) + "'";
         res.prepare_payload();
         return res;
     };
