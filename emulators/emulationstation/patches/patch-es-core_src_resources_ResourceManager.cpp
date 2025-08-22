$NetBSD: patch-es-core_src_resources_ResourceManager.cpp,v 1.1 2025/08/22 05:31:50 adam Exp $

Find resources in share/emulationstation/resources.

--- es-core/src/resources/ResourceManager.cpp.orig	2025-08-22 05:14:18.446070416 +0000
+++ es-core/src/resources/ResourceManager.cpp
@@ -33,7 +33,7 @@ std::string ResourceManager::getResource
 			return test;
 
 		// check in exepath
-		test = Utils::FileSystem::getExePath() + "/resources/" + &path[2];
+		test = Utils::FileSystem::getExePath() + "/../share/emulationstation/resources/" + &path[2];
 		if(Utils::FileSystem::exists(test))
 			return test;
 
