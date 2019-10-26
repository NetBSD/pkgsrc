$NetBSD: patch-simsys.cc,v 1.1 2019/10/26 11:27:10 nia Exp $

Support XDG_CONFIG_HOME.

--- simsys.cc.orig	2018-07-25 20:56:16.000000000 +0000
+++ simsys.cc
@@ -359,7 +359,12 @@ char const *dr_query_homedir()
 	find_directory(B_USER_DIRECTORY, &userDir);
 	sprintf(buffer, "%s/simutrans", userDir.Path());
 #else
-	sprintf(buffer, "%s/simutrans", getenv("HOME"));
+	char *config_dir = getenv("XDG_CONFIG_HOME");
+	if (config_dir != NULL) {
+		snprintf(buffer, sizeof(buffer), "%s/simutrans", config_dir);
+	} else {
+		snprintf(buffer, sizeof(buffer), "%s/.config/simutrans", getenv("HOME"));
+	}
 #endif
 
 	// create directory and subdirectories
