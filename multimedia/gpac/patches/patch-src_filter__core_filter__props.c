$NetBSD: patch-src_filter__core_filter__props.c,v 1.1 2023/12/15 13:05:53 schmonz Exp $

Work around clang 15 optimizing to memrchr (which macOS doesn't have).
Adapted from upstream commit ce22027.

--- src/filter_core/filter_props.c.orig	2023-12-15 12:55:29.610511221 +0000
+++ src/filter_core/filter_props.c
@@ -41,7 +41,7 @@ GF_PropertyValue gf_props_parse_value(u3
 	unit_sep = NULL;
 	if (value) {
 		u32 len = (u32) strlen(value);
-		unit_sep = len ? strrchr("kKgGmM", value[len-1]) : NULL;
+		unit_sep = len ? strchr("MmGgKk", value[len-1]) : NULL;
 		if (unit_sep) {
 			u8 unit_char = unit_sep[0];
 			if ((unit_char=='k') || (unit_char=='K')) unit = 1000;
