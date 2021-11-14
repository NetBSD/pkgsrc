$NetBSD: patch-apps_app__directory.c,v 1.1 2021/11/14 02:30:21 jnemeth Exp $

--- apps/app_directory.c.orig	2018-05-07 17:19:54.317128994 +0000
+++ apps/app_directory.c
@@ -194,7 +194,7 @@ static int compare(const char *text, con
 	}
 
 	while (*template) {
-		digit = toupper(*text++);
+		digit = toupper((unsigned char)*text++);
 		switch (digit) {
 		case 0:
 			return -1;
