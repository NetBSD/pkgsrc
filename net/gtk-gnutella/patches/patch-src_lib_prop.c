$NetBSD: patch-src_lib_prop.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/lib/prop.c.orig	2022-02-25 16:06:22.000000000 +0000
+++ src/lib/prop.c
@@ -2382,7 +2382,7 @@ prop_load_from_file(prop_set_t *ps, cons
 	 * ([[:blank:]]*)(("[^"]*")|([^[:space:]]*))
 	 *
 	 */
-	while (fgets(ARYLEN(prop_tmp), config)) {
+	while (fgets(prop_tmp, sizeof(prop_tmp), config)) {
 		char *s, *k, *v;
 		int c;
 		property_t prop;
