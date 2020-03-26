$NetBSD: patch-src_wp_ap_gtk_ap__UnixApp.cpp,v 1.1 2020/03/26 02:36:02 joerg Exp $

--- src/wp/ap/gtk/ap_UnixApp.cpp.orig	2020-03-25 14:42:03.508260820 +0000
+++ src/wp/ap/gtk/ap_UnixApp.cpp
@@ -863,7 +863,7 @@ static bool is_so (const char *file) {
 	if (len < (strlen(G_MODULE_SUFFIX) + 2)) // this is ".so" and at least one char for the filename
 		return false;
 	const char *suffix = file+(len-3);
-	if(0 == strcmp (suffix, "."G_MODULE_SUFFIX))
+	if(0 == strcmp (suffix, "." G_MODULE_SUFFIX))
 		return true;
 	return false;
 }
