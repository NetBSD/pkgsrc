$NetBSD: patch-client_client__connection.cpp,v 1.1 2025/01/31 16:20:06 wiz Exp $

Fix build with boost 1.87.
Using current upstream code.

--- client/client_connection.cpp.orig	2025-01-31 16:06:01.103330476 +0000
+++ client/client_connection.cpp
@@ -60,10 +60,9 @@ std::string ClientConnection::getMacAddr
 
 void ClientConnection::connect(const ResultHandler& handler)
 {
-    tcp::resolver::query query(server_.host, cpt::to_string(server_.port), boost::asio::ip::resolver_query_base::numeric_service);
     boost::system::error_code ec;
     LOG(INFO, LOG_TAG) << "Resolving host IP for: " << server_.host << "\n";
-    auto iterator = resolver_.resolve(query, ec);
+    auto iterator = resolver_.resolve(server_.host, cpt::to_string(server_.port), boost::asio::ip::resolver_query_base::numeric_service, ec);
     if (ec)
     {
         LOG(ERROR, LOG_TAG) << "Failed to resolve host '" << server_.host << "', error: " << ec.message() << "\n";
@@ -71,15 +70,25 @@ void ClientConnection::connect(const Res
         return;
     }
 
-    LOG(INFO, LOG_TAG) << "Connecting\n";
-    socket_.connect(*iterator, ec);
-    if (ec)
+    for (const auto& iter : iterator)
+        LOG(DEBUG, LOG_TAG) << "Resolved IP: " << iter.endpoint().address().to_string() << "\n";
+
+    for (const auto& iter : iterator)
     {
-        LOG(ERROR, LOG_TAG) << "Failed to connect to host '" << server_.host << "', error: " << ec.message() << "\n";
-        handler(ec);
-        return;
+        LOG(INFO, LOG_TAG) << "Connecting to " << iter.endpoint() << "\n";
+        socket_.connect(iter, ec);
+        if (!ec || (ec == boost::system::errc::interrupted))
+        {
+            // We were successful or interrupted, e.g. by sig int
+            break;
+        }
     }
-    LOG(NOTICE, LOG_TAG) << "Connected to " << socket_.remote_endpoint().address().to_string() << endl;
+
+    if (ec)
+        LOG(ERROR, LOG_TAG) << "Failed to connect to host '" << server_.host << "', error: " << ec.message() << "\n";
+    else
+        LOG(NOTICE, LOG_TAG) << "Connected to " << socket_.remote_endpoint().address().to_string() << endl;
+
     handler(ec);
 
 #if 0
