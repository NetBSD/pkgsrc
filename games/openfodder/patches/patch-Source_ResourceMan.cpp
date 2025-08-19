$NetBSD: patch-Source_ResourceMan.cpp,v 1.2 2025/08/19 11:29:40 wiz Exp $

Load static data from pkgsrc prefix.

--- Source/ResourceMan.cpp.orig	2024-10-23 08:21:54.121186053 +0000
+++ Source/ResourceMan.cpp
@@ -81,7 +81,7 @@ void cResourceMan::addDefaultDirs() {
 		path = path1;
 		addBaseDir(path + "/.local/share/");
 	}
-	addBaseDir("/usr/local/share/");
+	addBaseDir("@PREFIX@/share/");
 #endif
 }
 
