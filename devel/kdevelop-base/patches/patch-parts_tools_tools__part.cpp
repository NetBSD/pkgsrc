$NetBSD: patch-parts_tools_tools__part.cpp,v 1.1 2011/11/25 21:45:02 joerg Exp $

--- parts/tools/tools_part.cpp.orig	2011-11-25 18:57:13.000000000 +0000
+++ parts/tools/tools_part.cpp
@@ -154,7 +154,7 @@ void ToolsPart::startCommand(QString cmd
     if (captured)
     {
        if (KDevAppFrontend *appFrontend = extension<KDevAppFrontend>("KDevelop/AppFrontend"))
-            appFrontend->startAppCommand(QString::QString(), cmdline, false);
+            appFrontend->startAppCommand(QString(), cmdline, false);
     }
     else 
     {
