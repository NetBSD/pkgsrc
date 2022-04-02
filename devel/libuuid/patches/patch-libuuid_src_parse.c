$NetBSD: patch-libuuid_src_parse.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- libuuid/src/parse.c.orig	2017-09-18 09:48:03.575891419 +0000
+++ libuuid/src/parse.c
@@ -59,7 +59,7 @@ int uuid_parse(const char *in, uuid_t uu
 		if (i== 36)
 			if (*cp == 0)
 				continue;
-		if (!isxdigit(*cp))
+		if (!isxdigit((unsigned char)*cp))
 			return -1;
 	}
 	uuid.time_low = strtoul(in, NULL, 16);
