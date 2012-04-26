$NetBSD: patch-kimap_loginjob.cpp,v 1.1 2012/04/26 13:22:42 hans Exp $

--- kimap/loginjob.cpp.orig	2012-02-29 23:56:04.000000000 +0100
+++ kimap/loginjob.cpp	2012-04-26 14:32:19.144049407 +0200
@@ -260,7 +260,7 @@ void LoginJob::handleResponse( const Mes
 
   enum ResponseCode {
     OK,
-    ERR,
+    ERROR,
     UNTAGGED,
     CONTINUATION,
     MALFORMED
@@ -282,7 +282,7 @@ void LoginJob::handleResponse( const Mes
     else if ( response.content[1].toString() == "OK" )
       code = OK;
     else
-      code = ERR;
+      code = ERROR;
   }
 
   switch (code) {
@@ -290,7 +290,7 @@ void LoginJob::handleResponse( const Mes
       // We'll handle it later
       break;
 
-    case ERR:
+    case ERROR:
       //server replied with NO or BAD for SASL authentication
       if (d->authState == LoginJobPrivate::Authenticate)
         sasl_dispose( &d->conn );
