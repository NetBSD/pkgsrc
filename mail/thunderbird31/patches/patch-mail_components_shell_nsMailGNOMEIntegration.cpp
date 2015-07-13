$NetBSD: patch-mail_components_shell_nsMailGNOMEIntegration.cpp,v 1.1 2015/07/13 17:49:26 ryoon Exp $

Avoid warning storing a size_t in an unsigned int on LP64

--- mail/components/shell/nsMailGNOMEIntegration.cpp.orig	2014-07-18 00:04:06.000000000 +0000
+++ mail/components/shell/nsMailGNOMEIntegration.cpp
@@ -50,15 +50,15 @@ struct AppTypeAssociation {
 
 static const AppTypeAssociation sAppTypes[] = {
   {
-    nsIShellService::MAIL, sMailProtocols, ArrayLength(sMailProtocols),
+    nsIShellService::MAIL, sMailProtocols, (unsigned int)ArrayLength(sMailProtocols),
     "message/rfc822", "eml"
   },
   {
-    nsIShellService::NEWS, sNewsProtocols, ArrayLength(sNewsProtocols),
+    nsIShellService::NEWS, sNewsProtocols, (unsigned int)ArrayLength(sNewsProtocols),
     nullptr, nullptr
   },
   {
-    nsIShellService::RSS, sFeedProtocols, ArrayLength(sFeedProtocols),
+    nsIShellService::RSS, sFeedProtocols, (unsigned int)ArrayLength(sFeedProtocols),
     "application/rss+xml", "rss"
   }
 };
