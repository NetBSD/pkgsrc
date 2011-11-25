$NetBSD: patch-readconfig.c,v 1.1 2011/11/25 22:10:16 joerg Exp $

--- readconfig.c.orig	2011-11-25 14:10:26.000000000 +0000
+++ readconfig.c
@@ -52,7 +52,7 @@ pJ_read_config(FILE * pConfigFile, char 
 	 */
 
 	for (nFields = 0; 
-			(((char *) pFields) + (nFields * nSize))[0] != (char) NULL;
+			(((char *) pFields) + (nFields * nSize))[0] != '\0';
 			nFields++);
 
 	Q_INIT(pCH, sizeof(*pCH));
@@ -61,7 +61,7 @@ pJ_read_config(FILE * pConfigFile, char 
 	while (fgets(szSlusk, J_CONF_STR, pConfigFile)) {
 		if ((strlen(szSlusk) != 0) &&
 		    (szSlusk[strlen(szSlusk) - 1] == '\n'))
-			szSlusk[strlen(szSlusk) - 1] = (char) NULL;
+			szSlusk[strlen(szSlusk) - 1] = '\0';
 
 		szRow = strdup(szSlusk);
 		nRow++;
