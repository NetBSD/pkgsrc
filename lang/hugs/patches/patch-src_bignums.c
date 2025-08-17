$NetBSD: patch-src_bignums.c,v 1.1 2025/08/17 20:07:06 pho Exp $

Fix a sign extension bug [pkg/43609]

Hugs no longer has a maintainer. Its development has stopped as of
2006. Nowhere to send this patch.

--- src/bignums.c.orig	2004-10-29 12:43:09.000000000 +0000
+++ src/bignums.c
@@ -117,7 +117,7 @@ Int n; {
 	unsigned long no;
 	Cell nx;
 	if (n<0) {
-	    no = (unsigned long)(-n);
+	    no = (unsigned long)(-(long)n);
 	    bn = pair(NEGNUM,NIL);
 	}
 	else {
