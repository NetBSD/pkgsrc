$NetBSD: patch-src_main.cpp,v 1.1 2019/07/09 16:33:30 nia Exp $

get_current_dir_name is not portable.

--- src/main.cpp.orig	2018-06-02 09:25:36.000000000 +0000
+++ src/main.cpp
@@ -396,9 +396,12 @@ int main(int argc, char* argv[])
 	//When running in a local sandbox, set the root URL to the current working dir
 	else if(sandboxType != SecurityManager::REMOTE)
 	{
-		char * cwd = get_current_dir_name();
+		char cwd[PATH_MAX];
+		if (getcwd(cwd, PATH_MAX) == NULL) {
+		    LOG(LOG_ERROR,_("getcwd failed"));
+		    exit(1);
+		}
 		string cwdStr = string("file://") + string(cwd);
-		free(cwd);
 		cwdStr += "/";
 		sys->mainClip->setOrigin(cwdStr, fileName);
 	}
