$NetBSD: patch-src_color-man-heif.cc,v 1.1 2026/05/07 13:42:09 wiz Exp $

Avoid warning when file was deleted/moved.
https://github.com/BestImageViewer/geeqie/issues/2316

--- src/color-man-heif.cc.orig	2026-05-04 07:10:22.118496497 +0000
+++ src/color-man-heif.cc
@@ -288,7 +288,8 @@ guchar *heif_color_profile(const gchar *path, guint &p
 		}
 	catch (const heif::Error &error)
 		{
-		if (error.get_code() != heif_error_Color_profile_does_not_exist)
+		if (error.get_code() != heif_error_Color_profile_does_not_exist &&
+		    error.get_code() != heif_error_Input_does_not_exist)
 			{
 			log_printf("warning: heif reader error: %d (%s)\n",
 			           error.get_code(), error.get_message().c_str());
