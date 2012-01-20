$NetBSD: patch-src_users_user-profiles.c,v 1.1 2012/01/20 17:01:07 joerg Exp $

--- src/users/user-profiles.c.orig	2012-01-19 00:04:05.000000000 +0000
+++ src/users/user-profiles.c
@@ -170,7 +170,7 @@ gst_user_profiles_set_current (GstUserPr
 {
 	GstUserProfilesPrivate *priv;
 
-	g_return_if_fail (GST_IS_USER_PROFILES (profiles));
+	g_return_val_if_fail (GST_IS_USER_PROFILES (profiles), NULL);
 
 	priv = GST_USER_PROFILES_GET_PRIVATE (profiles);
 
@@ -184,7 +184,7 @@ gst_user_profiles_get_current (GstUserPr
 {
 	GstUserProfilesPrivate *priv;
 
-	g_return_if_fail (GST_IS_USER_PROFILES (profiles));
+	g_return_val_if_fail (GST_IS_USER_PROFILES (profiles), NULL);
 
 	priv = GST_USER_PROFILES_GET_PRIVATE (profiles);
 
@@ -196,7 +196,7 @@ gst_user_profiles_get_default_profile (G
 {
 	GstUserProfilesPrivate *priv;
 
-	g_return_if_fail (GST_IS_USER_PROFILES (profiles));
+	g_return_val_if_fail (GST_IS_USER_PROFILES (profiles), NULL);
 
 	priv = GST_USER_PROFILES_GET_PRIVATE (profiles);
 
