$NetBSD: patch-terms.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- terms.c.orig	2012-12-20 14:38:09.000000000 +0000
+++ terms.c
@@ -124,7 +124,7 @@ getTCstr()
 	}
 }
 
-setEnvirons()
+void setEnvirons(void)
 {
 	extern char *version;
 	char buf[1024], *p, *q, *e, c1, c2;
