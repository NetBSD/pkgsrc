$NetBSD: patch-erts_etc_common_dialyzer.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/etc/common/dialyzer.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/etc/common/dialyzer.c
@@ -297,13 +297,13 @@ push_words(char* src)
 
     dst = sbuf;
     while ((*dst++ = *src++) != '\0') {
-	if (isspace((int)*src)) {
+	if (isspace((unsigned char)*src)) {
 	    *dst = '\0';
 	    PUSH(strsave(sbuf));
 	    dst = sbuf;
 	    do {
 		src++;
-	    } while (isspace((int)*src));
+	    } while (isspace((unsigned char)*src));
 	}
     }
     if (sbuf[0])
