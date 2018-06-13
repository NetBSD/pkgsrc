$NetBSD: patch-lib_colord_cd-icc-store.c,v 1.1 2018/06/13 15:49:40 youri Exp $

Fix db path and prefix.

--- lib/colord/cd-icc-store.c.orig	2015-10-13 15:24:13.000000000 +0000
+++ lib/colord/cd-icc-store.c
@@ -206,7 +206,7 @@ cd_icc_store_add_icc (CdIccStore *store,
 	icc = cd_icc_new ();
 	filename = g_file_get_path (file);
 	if (priv->cache != NULL) {
-		if (g_str_has_prefix (filename, "/usr/share/color/icc/colord/")) {
+		if (g_str_has_prefix (filename, "@PREFIX@/share/color/icc/colord/")) {
 			g_autofree gchar *cache_key = NULL;
 			cache_key = g_build_filename ("/org/freedesktop/colord",
 						      "profiles",
@@ -622,11 +622,11 @@ cd_icc_store_search_kind (CdIccStore *st
 		break;
 	case CD_ICC_STORE_SEARCH_KIND_MACHINE:
 		g_ptr_array_add (locations, g_strdup (CD_SYSTEM_PROFILES_DIR));
-		g_ptr_array_add (locations, g_strdup ("/var/lib/color/icc"));
+		g_ptr_array_add (locations, g_strdup ("@VARBASE@/db/color/icc"));
 		break;
 	case CD_ICC_STORE_SEARCH_KIND_SYSTEM:
 		g_ptr_array_add (locations, g_strdup ("/usr/share/color/icc"));
-		g_ptr_array_add (locations, g_strdup ("/usr/local/share/color/icc"));
+		g_ptr_array_add (locations, g_strdup ("@PREFIX@/share/color/icc"));
 		g_ptr_array_add (locations, g_strdup ("/Library/ColorSync/Profiles/Displays"));
 		break;
 	default:
