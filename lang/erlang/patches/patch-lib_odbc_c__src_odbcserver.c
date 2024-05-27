$NetBSD: patch-lib_odbc_c__src_odbcserver.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- lib/odbc/c_src/odbcserver.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ lib/odbc/c_src/odbcserver.c
@@ -2800,6 +2800,6 @@ static void str_tolower(char *str, int l
 	int i;
 	
 	for(i = 0; i <= len; i++) {
-		str[i] = tolower(str[i]);
+		str[i] = tolower((unsigned char)str[i]);
 	}
 }
