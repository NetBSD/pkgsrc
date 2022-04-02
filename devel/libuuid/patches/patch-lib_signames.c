$NetBSD: patch-lib_signames.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/signames.c.orig	2018-06-04 07:57:02.794445874 +0000
+++ lib/signames.c
@@ -144,7 +144,7 @@ static int rtsig_to_signum(const char *s
 		sig += 4;
 		maxi = 1;
 	}
-	if (!isdigit(*sig))
+	if (!isdigit((unsigned char)*sig))
 		return -1;
 	errno = 0;
 	num = strtol(sig, &ep, 10);
