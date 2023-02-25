$NetBSD: patch-src_tftp.c,v 1.1 2023/02/25 03:30:47 riastradh Exp $

Fix ctype(3) misuse.

--- src/tftp.c.orig	2023-02-02 20:24:24.000000000 +0000
+++ src/tftp.c
@@ -405,7 +405,7 @@ void tftp_request(struct listener *liste
 	if (*p == '\\')
 	  *p = '/';
 	else if (option_bool(OPT_TFTP_LC))
-	  *p = tolower(*p);
+	  *p = tolower((unsigned char)*p);
 		
       strcpy(daemon->namebuff, "/");
       if (prefix)
