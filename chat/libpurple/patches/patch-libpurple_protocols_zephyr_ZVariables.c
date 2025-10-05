$NetBSD: patch-libpurple_protocols_zephyr_ZVariables.c,v 1.1 2025/10/05 16:01:16 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/zephyr/ZVariables.c~	2025-01-21 17:44:24.000000000 +0100
+++ libpurple/protocols/zephyr/ZVariables.c	2025-10-05 15:14:01.480961180 +0200
@@ -198,7 +198,7 @@
 	return (0);
 
     cp = bfr;
-    while (*cp && !isspace(*cp) && (*cp != '='))
+    while (*cp && !isspace((unsigned char)*cp) && (*cp != '='))
 	cp++;
 
 #ifndef WIN32
@@ -213,7 +213,7 @@
     if (!cp)
 	return(0);
     cp++;
-    while (*cp && isspace(*cp))		/* space up to variable value */
+    while (*cp && isspace((unsigned char)*cp))		/* space up to variable value */
 	cp++;
 
     return (cp - bfr);			/* return index */
