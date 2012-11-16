$NetBSD: patch-examples_ktcli_main.cpp,v 1.1 2012/11/16 01:05:33 joerg Exp $

--- examples/ktcli/main.cpp.orig	2012-11-15 12:19:45.000000000 +0000
+++ examples/ktcli/main.cpp
@@ -66,11 +66,11 @@ int main(int argc, char** argv)
 		KCmdLineArgs::addCmdLineOptions(options);
 		KCmdLineArgs::init(argc,argv,"ktcli","ktorrent",ki18n("ktcli"),bt::GetVersionString().toAscii());
 		
-		KTCLI app;
-		if (!app.start())
+		KTCLI app2;
+		if (!app2.start())
 			return -1;
 		else
-			return app.exec();
+			return app2.exec();
 	}
 	catch (bt::Error & err)
 	{
