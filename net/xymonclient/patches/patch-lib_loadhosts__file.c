$NetBSD: patch-lib_loadhosts__file.c,v 1.1 2026/07/28 21:23:17 wiz Exp $

Fix ctype(3) usage.

--- lib/loadhosts_file.c.orig	2026-07-28 21:21:15.668395905 +0000
+++ lib/loadhosts_file.c
@@ -175,7 +175,7 @@ int load_hostnames(char *hostsfn, char *extrainclude, 
 		inbol += strspn(inbol, " \t");
 		ineol = strchr(inbol, '\n'); 
 		if (ineol) {
-			while ((ineol > inbol) && (isspace(*ineol) || (*ineol == '\n'))) ineol--;
+			while ((ineol > inbol) && (isspace((unsigned char)*ineol) || (*ineol == '\n'))) ineol--;
 			if (*ineol != '\n') ineol++;
 
 			insavchar = *ineol;
