$NetBSD: patch-src_ft2__config.c,v 1.1 2020/11/29 14:53:28 fox Exp $

Fix build errors.

--- src/ft2_config.c.orig	2020-11-29 14:09:46.787282062 +0000
+++ src/ft2_config.c
@@ -633,7 +633,7 @@ static void setConfigFileLocation(void) 
 	{
 		if (chdir(getenv("HOME")) == 0)
 		{
-			result = chdir(".config");
+			int32_t result = chdir(".config");
 			if (result != 0)
 			{
 				mkdir(".config", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
