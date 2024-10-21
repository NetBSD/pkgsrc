$NetBSD: patch-main_app.c,v 1.1 2024/10/21 05:12:46 jnemeth Exp $

--- main/app.c.orig	2018-05-07 17:23:29.870389813 +0000
+++ main/app.c
@@ -3085,7 +3085,7 @@ int ast_app_parse_timelen(const char *ti
 			break;
 		case 'm':
 		case 'M':
-			if (toupper(u[1]) == 'S') {
+			if (toupper((unsigned char)u[1]) == 'S') {
 				unit = TIMELEN_MILLISECONDS;
 				if (u[2] != '\0') {
 					return -1;
