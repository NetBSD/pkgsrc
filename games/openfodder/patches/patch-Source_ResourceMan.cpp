$NetBSD: patch-Source_ResourceMan.cpp,v 1.1 2024/10/23 08:30:30 nia Exp $

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
 
@@ -624,4 +624,4 @@ std::vector<std::string> cResourceMan::D
 	return results;
 }
 
-#endif
\ No newline at end of file
+#endif
