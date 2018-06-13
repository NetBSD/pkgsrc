$NetBSD: patch-src_cd-main.c,v 1.1 2018/06/13 15:49:40 youri Exp $

Adjust paths.

--- src/cd-main.c.orig	2016-07-27 13:55:24.000000000 +0000
+++ src/cd-main.c
@@ -1716,8 +1716,8 @@ cd_main_icc_store_added_cb (CdIccStore *
 	/* create profile */
 	profile = cd_profile_new ();
 	filename = cd_icc_get_filename (icc);
-	if (g_str_has_prefix (filename, "/usr/share/color") ||
-	    g_str_has_prefix (filename, "/var/lib/color"))
+	if (g_str_has_prefix (filename, "@PREFIX@/share/color") ||
+	    g_str_has_prefix (filename, "@VARBASE@/db/color"))
 		cd_profile_set_is_system_wide (profile, TRUE);
 
 	/* parse the profile name */
@@ -2590,7 +2590,7 @@ main (int argc, char *argv[])
 	/* connect to the mapping db */
 	priv->mapping_db = cd_mapping_db_new ();
 	ret = cd_mapping_db_load (priv->mapping_db,
-				  LOCALSTATEDIR "/lib/colord/mapping.db",
+				  LOCALSTATEDIR "/db/colord/mapping.db",
 				  &error);
 	if (!ret) {
 		g_warning ("CdMain: failed to load mapping database: %s",
@@ -2601,7 +2601,7 @@ main (int argc, char *argv[])
 	/* connect to the device db */
 	priv->device_db = cd_device_db_new ();
 	ret = cd_device_db_load (priv->device_db,
-				 LOCALSTATEDIR "/lib/colord/storage.db",
+				 LOCALSTATEDIR "/db/colord/storage.db",
 				 &error);
 	if (!ret) {
 		g_warning ("CdMain: failed to load device database: %s",
@@ -2612,7 +2612,7 @@ main (int argc, char *argv[])
 	/* connect to the profile db */
 	priv->profile_db = cd_profile_db_new ();
 	ret = cd_profile_db_load (priv->profile_db,
-				  LOCALSTATEDIR "/lib/colord/storage.db",
+				  LOCALSTATEDIR "/db/colord/storage.db",
 				  &error);
 	if (!ret) {
 		g_warning ("CdMain: failed to load profile database: %s",
