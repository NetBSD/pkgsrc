$NetBSD: patch-xen_tools_symbols.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $
symbols.c:180:2: error: array subscript has type 'char' [-Werror=char-subscripts]

--- ./xen/tools/symbols.c	2018-04-23 18:11:57.000000000 +0200
+++ ./xen/tools/symbols.c.orig	2018-04-23 18:13:15.000000000 +0200
@@ -173,11 +173,11 @@
 	/* include the type field in the symbol name, so that it gets
 	 * compressed together */
 	s->len = strlen(str) + 1;
-	if (islower(stype) && filename)
+	if (islower((unsigned char)stype) && filename)
 		s->len += strlen(filename) + 1;
 	s->sym = malloc(s->len + 1);
 	sym = SYMBOL_NAME(s);
-	if (islower(stype) && filename) {
+	if (islower((unsigned char)stype) && filename) {
 		sym = stpcpy(sym, filename);
 		*sym++ = '#';
 	}
