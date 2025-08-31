$NetBSD: patch-src_match.c,v 1.2 2025/08/31 10:44:08 leot Exp $

Fix ctype(3) abuse

Shared upstream via <https://github.com/jhawthorn/fzy/pull/197>.

--- src/match.c.orig	2025-08-31 10:15:49.302462188 +0000
+++ src/match.c
@@ -59,10 +59,10 @@ static void setup_match_struct(struct ma
 	}
 
 	for (int i = 0; i < match->needle_len; i++)
-		match->lower_needle[i] = tolower(needle[i]);
+		match->lower_needle[i] = tolower((unsigned char)needle[i]);
 
 	for (int i = 0; i < match->haystack_len; i++)
-		match->lower_haystack[i] = tolower(haystack[i]);
+		match->lower_haystack[i] = tolower((unsigned char)haystack[i]);
 
 	precompute_bonus(haystack, match->match_bonus);
 }
