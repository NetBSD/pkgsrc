$NetBSD: patch-src_s__info.c,v 1.1 2015/11/07 22:00:16 dholland Exp $

Fix bounding errors detected by OpenBSD's compiler.

--- src/s_info.c~	2006-05-11 03:44:53.000000000 +0000
+++ src/s_info.c
@@ -18,7 +18,7 @@ s_info(int n, int argc)
 	int	TheirIndex;
 
         if (argc == 2) {
-		strlcpy(TheirName, getword(fields[1]), 20);
+		strlcpy(TheirName, getword(fields[1]), sizeof(TheirName));
 
 		TheirIndex = find_user(TheirName);
 
