$NetBSD: patch-languages_csharp_csharpsupportpart.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- languages/csharp/csharpsupportpart.cpp.orig	2011-11-25 19:24:37.000000000 +0000
+++ languages/csharp/csharpsupportpart.cpp
@@ -194,7 +194,7 @@ void CSharpSupportPart::startApplication
 {
     bool inTerminal = DomUtil::readBoolEntry(*projectDom(), "/kdevcsharpsupport/run/terminal");
     if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-        appFrontend->startAppCommand(QString::QString(), program, inTerminal);
+        appFrontend->startAppCommand(QString(), program, inTerminal);
 }
 
 
