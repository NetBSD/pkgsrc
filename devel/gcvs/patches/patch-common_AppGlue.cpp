$NetBSD: patch-common_AppGlue.cpp,v 1.1 2020/04/17 00:21:56 joerg Exp $

--- common/AppGlue.cpp.orig	2020-04-16 19:58:12.070945815 +0000
+++ common/AppGlue.cpp
@@ -260,7 +260,7 @@ CVS_EXTERN_C const char *glue_getenv(cha
 		// extract from the cvsroot
 		const char *ccvsroot = gCvsPrefs;
 		ccvsroot = Authen::skiptoken(ccvsroot);
-		char *login = strchr(ccvsroot, '@');
+		const char *login = strchr(ccvsroot, '@');
 		if(login == NULL)
 		{
 			// for WIN32 this means the CVSROOT is local
