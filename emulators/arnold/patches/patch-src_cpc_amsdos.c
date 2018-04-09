$NetBSD: patch-src_cpc_amsdos.c,v 1.1 2018/04/09 15:03:22 ryoon Exp $

--- src/cpc/amsdos.c.orig	2004-01-03 23:22:58.000000000 +0000
+++ src/cpc/amsdos.c
@@ -559,11 +559,11 @@ int AMSDOS_GetPrefixPriority(const char 
 
 		/* default prefixes in order searched for by AMSDOS */
 		/* assign higher priority to order prefixes are used */
-		if (stricmp(pExtension,"   ")==0)
+		if (strcmp(pExtension,"   ")==0)
 			return 3;
-		if (stricmp(pExtension,"BAS")==0)
+		if (strcmp(pExtension,"BAS")==0)
 			return 2;
-		if (stricmp(pExtension,"BIN")==0)
+		if (strcmp(pExtension,"BIN")==0)
 			return 1;
 	}
 
