$NetBSD: patch-lib_canonicalize.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- lib/canonicalize.c.orig	2024-01-31 10:02:15.454811603 +0000
+++ lib/canonicalize.c
@@ -69,7 +69,7 @@ static int is_dm_devname(char *canonical
 
 	if (!p
 	    || strncmp(p, "/dm-", 4) != 0
-	    || !isdigit(*(p + 4))
+	    || !isdigit((unsigned char)*(p + 4))
 	    || stat(canonical, &sb) != 0
 	    || !S_ISBLK(sb.st_mode))
 		return 0;
