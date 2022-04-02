$NetBSD: patch-lib_canonicalize.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/canonicalize.c.orig	2018-07-11 13:34:54.227003733 +0000
+++ lib/canonicalize.c
@@ -57,7 +57,7 @@ static int is_dm_devname(char *canonical
 
 	if (!p
 	    || strncmp(p, "/dm-", 4) != 0
-	    || !isdigit(*(p + 4))
+	    || !isdigit((unsigned char)*(p + 4))
 	    || stat(canonical, &sb) != 0
 	    || !S_ISBLK(sb.st_mode))
 		return 0;
