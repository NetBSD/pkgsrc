$NetBSD: patch-languages_perl_perlsupportpart.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- languages/perl/perlsupportpart.cpp.orig	2011-11-25 19:30:48.000000000 +0000
+++ languages/perl/perlsupportpart.cpp
@@ -194,7 +194,7 @@ void PerlSupportPart::startApplication(c
 {
     bool inTerminal = DomUtil::readBoolEntry(*projectDom(), "/kdevperlsupport/run/terminal");
     if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-        appFrontend->startAppCommand(QString::QString(), program, inTerminal);
+        appFrontend->startAppCommand(QString(), program, inTerminal);
 }
 
 
