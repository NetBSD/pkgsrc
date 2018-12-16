$NetBSD: patch-comm_mail_components_shell_nsMailGNOMEIntegration.cpp,v 1.1 2018/12/16 08:12:15 ryoon Exp $

--- comm/mail/components/shell/nsMailGNOMEIntegration.cpp.orig	2018-12-04 23:12:16.000000000 +0000
+++ comm/mail/components/shell/nsMailGNOMEIntegration.cpp
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
