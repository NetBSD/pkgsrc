$NetBSD: patch-mail_components_shell_nsMailGNOMEIntegration.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

Avoid warning storing a size_t in an unsigned int on LP64

--- mail/components/shell/nsMailGNOMEIntegration.cpp.orig	2015-06-08 17:40:38.000000000 +0000
+++ mail/components/shell/nsMailGNOMEIntegration.cpp
@@ -50,16 +50,16 @@ struct AppTypeAssociation {
 
 static const AppTypeAssociation sAppTypes[] = {
   {
-    nsIShellService::MAIL, sMailProtocols, ArrayLength(sMailProtocols),
+    nsIShellService::MAIL, sMailProtocols, (unsigned int)ArrayLength(sMailProtocols),
     "message/rfc822",
     nullptr // don't associate .eml extension, as that breaks printing those
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
