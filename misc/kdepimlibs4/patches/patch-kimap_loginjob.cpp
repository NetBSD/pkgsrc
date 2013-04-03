$NetBSD: patch-kimap_loginjob.cpp,v 1.2 2013/04/03 10:51:48 markd Exp $

--- kimap/loginjob.cpp.orig	2013-03-01 06:58:43.000000000 +0000
+++ kimap/loginjob.cpp
@@ -282,7 +282,7 @@ void LoginJob::handleResponse( const Mes
 
   enum ResponseCode {
     OK,
-    ERR,
+    ERROR,
     UNTAGGED,
     CONTINUATION,
     MALFORMED
@@ -305,7 +305,7 @@ void LoginJob::handleResponse( const Mes
     } else if ( response.content[1].toString() == "OK" ) {
       code = OK;
     } else {
-      code = ERR;
+      code = ERROR;
     }
   }
 
@@ -314,7 +314,7 @@ void LoginJob::handleResponse( const Mes
       // We'll handle it later
       break;
 
-    case ERR:
+    case ERROR:
       //server replied with NO or BAD for SASL authentication
       if ( d->authState == LoginJobPrivate::Authenticate ) {
         sasl_dispose( &d->conn );
