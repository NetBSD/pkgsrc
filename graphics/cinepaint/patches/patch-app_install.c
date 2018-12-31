$NetBSD: patch-app_install.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/install.c.orig	2008-10-25 18:53:45.000000000 +0000
+++ app/install.c
@@ -475,7 +475,7 @@ install_run (InstallCallback callback)
 
   CP_TEXT_INSERT( font_strong, _("User Installation Log\n\n") );
 
-#if 1
+#if 0
 	{	const char* msg = UserInstall(gimp_directory());
 		if(msg)
 		{
