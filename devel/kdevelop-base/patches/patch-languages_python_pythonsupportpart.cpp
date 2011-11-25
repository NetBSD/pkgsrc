$NetBSD: patch-languages_python_pythonsupportpart.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- languages/python/pythonsupportpart.cpp.orig	2011-11-25 19:34:21.000000000 +0000
+++ languages/python/pythonsupportpart.cpp
@@ -328,7 +328,7 @@ void PythonSupportPart::startApplication
 {
     bool inTerminal = DomUtil::readBoolEntry(*projectDom(), "/kdevpythonsupport/run/terminal");
     if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-        appFrontend->startAppCommand(QString::QString(), program, inTerminal);
+        appFrontend->startAppCommand(QString(), program, inTerminal);
 }
 
 
