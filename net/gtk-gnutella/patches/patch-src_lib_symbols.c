$NetBSD: patch-src_lib_symbols.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/lib/symbols.c.orig	2022-02-25 16:06:22.000000000 +0000
+++ src/lib/symbols.c
@@ -1553,7 +1553,7 @@ symbols_load_from(symbols_t *st, const c
 #endif	/* MINGW32 */
 
 retry:
-	while (fgets(ARYLEN(tmp), f)) {
+	while (fgets(tmp, sizeof(tmp), f)) {
 		symbols_parse_nm(st, tmp);
 	}
 
