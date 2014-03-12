$NetBSD: patch-src_getline.c,v 1.1 2014/03/12 19:43:17 wiz Exp $

Export getline symbol if missing.

--- src/getline.c.orig	2013-01-11 19:36:54.000000000 +0000
+++ src/getline.c
@@ -76,7 +76,7 @@ getdelim(char **buf, size_t *bufsiz, int
 	}
 }
 
-ssize_t
+public ssize_t
 getline(char **buf, size_t *bufsiz, FILE *fp)
 {
 	return getdelim(buf, bufsiz, '\n', fp);
