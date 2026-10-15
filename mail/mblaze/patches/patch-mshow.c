$NetBSD: patch-mshow.c,v 1.1 2026/10/15 19:44:23 ktnb Exp $

NetBSD 11 ctype fix.

--- mshow.c.orig	2026-10-15 19:40:30.152827711 +0000
+++ mshow.c
@@ -67,7 +67,7 @@ printhdr(char *hdr)
 	int uc = 1;
 
 	while (*hdr && *hdr != ':' && printable(*hdr)) {
-		putc(uc ? toupper(*hdr) : *hdr, stdout);
+		putc(uc ? toupper((unsigned char)*hdr) : *hdr, stdout);
 		uc = (*hdr == '-');
 		hdr++;
 	}
