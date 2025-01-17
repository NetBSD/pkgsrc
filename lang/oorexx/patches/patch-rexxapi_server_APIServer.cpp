$NetBSD: patch-rexxapi_server_APIServer.cpp,v 1.1 2025/01/17 17:44:22 rhialto Exp $

Make terminateServer() resistant to being called more than once.
    https://sourceforge.net/p/oorexx/bugs/1993/

--- rexxapi/server/APIServer.cpp.orig	2025-01-14 14:01:33.240245578 +0000
+++ rexxapi/server/APIServer.cpp
@@ -64,8 +64,10 @@ void APIServer::initServer(ServerConnect
 void APIServer::terminateServer()
 {
     // flip the sign over to the closed side.
-    connectionManager->disconnect();
-    delete connectionManager;
+    if (connectionManager) {
+	connectionManager->disconnect();
+	delete connectionManager;
+    }
     connectionManager = NULL;
     serverActive = false;
 }
