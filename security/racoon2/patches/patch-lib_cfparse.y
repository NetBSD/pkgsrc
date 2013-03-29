$NetBSD: patch-lib_cfparse.y,v 1.1 2013/03/29 13:52:45 joerg Exp $

Fix type mismatch to avoid compilation error.

--- lib/cfparse.y.orig	2009-02-02 17:49:18.000000000 +0900
+++ lib/cfparse.y	2013-03-29 21:31:04.000000000 +0900
@@ -1712,7 +1712,7 @@
 	int n;
 	char *bp;
 	struct cf_list *new;
-	rcf_t type;
+	rc_type type;
 
 	n = strtoll(str, &bp, 10);
 
