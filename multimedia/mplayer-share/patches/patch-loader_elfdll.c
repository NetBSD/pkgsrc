$NetBSD: patch-loader_elfdll.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- loader/elfdll.c.orig	2025-10-08 03:45:22.180603031 +0000
+++ loader/elfdll.c
@@ -141,7 +141,7 @@ static LPSTR get_sobasename(LPCSTR path,
 	 * other modules are accessible.
 	 */
 	for(cptr = name; *cptr; cptr++)
-		*cptr = tolower(*cptr);
+		*cptr = tolower((unsigned char)(*cptr));
 
 	return name;
 }
