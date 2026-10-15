$NetBSD: patch-mpick.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- mpick.c.orig	2026-10-15 19:39:13.361637569 +0000
+++ mpick.c
@@ -405,10 +405,10 @@ parse_ident(char **sp, size_t *lp)
 parse_ident(char **sp, size_t *lp)
 {
 	char *p = pos;
-	if (!isalpha(*pos) && *pos != '_')
+	if (!isalpha((unsigned char)*pos) && *pos != '_')
 		return 0;
 	p++;
-	while (*p && (isalnum(*p) || *p == '_'))
+	while (*p && (isalnum((unsigned char)*p) || *p == '_'))
 		p++;
 	*sp = pos;
 	*lp = p-pos;
