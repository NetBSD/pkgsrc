$NetBSD: patch-file.c,v 1.1 2026/10/25 15:27:12 taca Exp $

* Pass correct type to ctype(3) function.

--- file.c.orig	2026-10-25 13:25:35.361730749 +0000
+++ file.c
@@ -102,7 +102,7 @@ fprintf(stderr, "file_loop: %s:%d bad et
 		cp = cp2;
 		if ((cp2 = strchr(cp, '\t')) != NULL)
 			*cp2++ = '\0';
-		if (!isdigit((int)*cp) || (int32_t)(a = inet_addr(cp)) == -1) {
+		if (!isdigit((unsigned char)*cp) || (int32_t)(a = inet_addr(cp)) == -1) {
 			if ((hp = gethostbyname(cp)) == NULL) {
 				syslog(LOG_ERR,
 				    "file_loop: %s:%d bad hostname \"%s\"",
