$NetBSD: patch-progs_dump__entry.c,v 1.1 2020/01/11 01:39:19 kim Exp $

Fix for CVE-2019-17595 cherry-picked from upstream patchlevel 20191012.
Additionally to the CVE fix, this contains a check for acsc with odd
length in dump_entry in check for one-one mapping.

https://bugs.debian.org/942401

--- progs/dump_entry.c
+++ progs/dump_entry.c
@@ -1110,7 +1110,8 @@ fmt_entry(TERMTYPE2 *tterm,
 				*d++ = '\\';
 				*d = ':';
 			    } else if (*d == '\\') {
-				*++d = *s++;
+				if ((*++d = *s++) == '\0')
+				    break;
 			    }
 			    d++;
 			    *d = '\0';
@@ -1370,7 +1371,7 @@ one_one_mapping(const char *mapping)
 
     if (VALID_STRING(mapping)) {
 	int n = 0;
-	while (mapping[n] != '\0') {
+	while (mapping[n] != '\0' && mapping[n + 1] != '\0') {
 	    if (isLine(mapping[n]) &&
 		mapping[n] != mapping[n + 1]) {
 		result = FALSE;
