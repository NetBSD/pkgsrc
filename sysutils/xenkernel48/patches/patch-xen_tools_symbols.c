$NetBSD: patch-xen_tools_symbols.c,v 1.1 2017/03/30 09:15:09 bouyer Exp $
fix "error: array subscript has type 'char'"

--- xen/tools/symbols.c.orig	2017-03-21 17:37:05.000000000 +0100
+++ xen/tools/symbols.c	2017-03-21 17:37:53.000000000 +0100
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
