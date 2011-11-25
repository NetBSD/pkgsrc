$NetBSD: patch-languages_ruby_rubysupport__part.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- languages/ruby/rubysupport_part.cpp.orig	2011-11-25 19:36:19.000000000 +0000
+++ languages/ruby/rubysupport_part.cpp
@@ -614,7 +614,7 @@ QString RubySupportPart::characterCoding
 void RubySupportPart::startApplication(const QString &program) {
 	bool inTerminal = DomUtil::readBoolEntry(*projectDom(), "/kdevrubysupport/run/terminal");
     if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-        appFrontend->startAppCommand(QString::QString(), program, inTerminal);
+        appFrontend->startAppCommand(QString(), program, inTerminal);
 }
 
 
