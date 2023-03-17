$NetBSD: patch-cli_main.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- cli/main.c.orig	2023-01-21 21:40:17.000000000 +0000
+++ cli/main.c
@@ -407,7 +407,8 @@ apply_env(pkgconf_client_t *client, pkgc
 	char workbuf[PKGCONF_ITEM_SIZE];
 
 	for (it = want_env_prefix; *it != '\0'; it++)
-		if (!isalpha(*it) && !isdigit(*it))
+		if (!isalpha((unsigned char)*it) &&
+		    !isdigit((unsigned char)*it))
 			return false;
 
 	snprintf(workbuf, sizeof workbuf, "%s_CFLAGS", want_env_prefix);
@@ -1327,7 +1328,7 @@ cleanup3:
 		if (maximum_package_count > 0 && pkgq.length > maximum_package_count)
 			break;
 
-		while (isspace((unsigned int)package[0]))
+		while (isspace((unsigned char)package[0]))
 			package++;
 
 		/* skip empty packages */
