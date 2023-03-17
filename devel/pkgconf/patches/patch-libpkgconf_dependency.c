$NetBSD: patch-libpkgconf_dependency.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/dependency.c.orig	2023-01-20 21:03:49.000000000 +0000
+++ libpkgconf/dependency.c
@@ -329,11 +329,11 @@ pkgconf_dependency_parse_str(pkgconf_cli
 			break;
 
 		case INSIDE_MODULE_NAME:
-			if (isspace((unsigned int)*ptr))
+			if (isspace((unsigned char)*ptr))
 			{
 				const char *sptr = ptr;
 
-				while (*sptr && isspace((unsigned int)*sptr))
+				while (*sptr && isspace((unsigned char)*sptr))
 					sptr++;
 
 				if (*sptr == '\0')
@@ -397,7 +397,7 @@ pkgconf_dependency_parse_str(pkgconf_cli
 			break;
 
 		case AFTER_OPERATOR:
-			if (!isspace((unsigned int)*ptr))
+			if (!isspace((unsigned char)*ptr))
 			{
 				vstart = ptr;
 				state = INSIDE_VERSION;
