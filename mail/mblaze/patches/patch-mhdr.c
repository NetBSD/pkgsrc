$NetBSD: patch-mhdr.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- mhdr.c.orig	2026-10-15 19:38:22.512423818 +0000
+++ mhdr.c
@@ -33,7 +33,7 @@ printhdr(char *hdr)
 		printf("%s\t", curfile);
 
 	while (*hdr && *hdr != ':') {
-		putc(uc ? toupper(*hdr) : *hdr, stdout);
+		putc(uc ? toupper((unsigned char)*hdr) : *hdr, stdout);
 		uc = (*hdr == '-');
 		hdr++;
 	}
