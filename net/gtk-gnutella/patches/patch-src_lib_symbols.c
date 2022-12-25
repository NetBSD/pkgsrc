$NetBSD: patch-src_lib_symbols.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/lib/symbols.c.orig	2022-02-25 16:06:22.000000000 +0000
+++ src/lib/symbols.c
@@ -1553,7 +1553,7 @@ symbols_load_from(symbols_t *st, const c
 #endif	/* MINGW32 */
 
 retry:
-	while (fgets(ARYLEN(tmp), f)) {
+	while (fgets(tmp, sizeof(tmp), f)) {
 		symbols_parse_nm(st, tmp);
 	}
 
