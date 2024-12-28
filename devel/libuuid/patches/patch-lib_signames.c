$NetBSD: patch-lib_signames.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- lib/signames.c.orig	2024-01-31 10:02:15.459811574 +0000
+++ lib/signames.c
@@ -114,7 +114,7 @@ static int rtsig_to_signum(const char *s
 		sig += 4;
 		maxi = 1;
 	}
-	if (!isdigit(*sig))
+	if (!isdigit((unsigned char)*sig))
 		return -1;
 	errno = 0;
 	num = strtol(sig, &ep, 10);
