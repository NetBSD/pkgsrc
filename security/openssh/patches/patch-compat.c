$NetBSD: patch-compat.c,v 1.1.2.2 2015/05/16 19:48:50 bsiegert Exp $

Use the correct buffer when calling strlen
http://www.openwall.com/lists/oss-security/2015/05/16/3

--- compat.c.orig	2015-05-16 13:05:33.000000000 +0000
+++ compat.c
@@ -223,7 +223,7 @@ filter_proposal(char *proposal, const ch
 	buffer_init(&b);
 	tmp = orig_prop = xstrdup(proposal);
 	while ((cp = strsep(&tmp, ",")) != NULL) {
-		if (match_pattern_list(cp, filter, strlen(cp), 0) != 1) {
+		if (match_pattern_list(cp, filter, strlen(filter), 0) != 1) {
 			if (buffer_len(&b) > 0)
 				buffer_append(&b, ",", 1);
 			buffer_append(&b, cp, strlen(cp));
