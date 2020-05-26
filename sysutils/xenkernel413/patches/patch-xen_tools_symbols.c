$NetBSD: patch-xen_tools_symbols.c,v 1.1 2020/05/26 11:12:10 bouyer Exp $
fix "error: array subscript has type 'char'"

--- xen/tools/symbols.c.orig	2018-04-17 19:21:31.000000000 +0200
+++ xen/tools/symbols.c	2018-04-23 13:29:47.000000000 +0200
@@ -173,11 +173,11 @@
 	/* include the type field in the symbol name, so that it gets
 	 * compressed together */
 	s->len = strlen(str) + 1;
-	if (islower(stype) && filename)
+	if (islower((uint8_t)stype) && filename)
 		s->len += strlen(filename) + 1;
 	s->sym = malloc(s->len + 1);
 	sym = SYMBOL_NAME(s);
-	if (islower(stype) && filename) {
+	if (islower((uint8_t)stype) && filename) {
 		sym = stpcpy(sym, filename);
 		*sym++ = '#';
 	}
