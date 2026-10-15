$NetBSD: patch-msed.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- msed.c.orig	2026-10-15 19:40:03.526630302 +0000
+++ msed.c
@@ -48,7 +48,7 @@ subst(char *str, char *srch, char *repl, char *flags)
 		char *t = repl;
 		while (*t) {
 			// & == \0
-			if (*t == '&' || (*t == '\\' && isdigit(*(t+1)))) {
+			if (*t == '&' || (*t == '\\' && isdigit((unsigned char)*(t+1)))) {
 				int n;
 				if (*t == '&') {
 					t++;
@@ -88,7 +88,7 @@ printhdr(char *hdr, int rest)
 	int uc = 1;
 
 	while (*hdr && *hdr != ':') {
-		putc(uc ? toupper(*hdr) : *hdr, stdout);
+		putc(uc ? toupper((unsigned char)*hdr) : *hdr, stdout);
 		uc = (*hdr == '-');
 		hdr++;
 	}
