$NetBSD: patch-libopenarc_arc.c,v 1.1 2023/04/21 00:49:56 manu Exp $

Fix buffer overrun

From upstream
https://github.com/trusteddomainproject/OpenARC/pull/117

--- libopenarc/arc.c.orig	2021-03-30 15:33:39.683325974 +0200
+++ libopenarc/arc.c	2021-03-30 15:34:50.693955186 +0200
@@ -2329,8 +2329,12 @@
 
 	while (end > hdr && isascii(*(end - 1)) && isspace(*(end - 1)))
 		end--;
 
+	/* don't allow incredibly large field names */
+	if (end - hdr > ARC_MAXHEADER)
+		return ARC_STAT_SYNTAX;
+
 	/* don't allow a field name containing a semicolon */
 	semicolon = memchr(hdr, ';', hlen);
 	if (semicolon != NULL && colon != NULL && semicolon < colon)
 		return ARC_STAT_SYNTAX;
@@ -2676,8 +2680,9 @@
 
 	for (h = msg->arc_hhead; h != NULL; h = h->hdr_next)
 	{
 		char hnbuf[ARC_MAXHEADER + 1];
+		assert(h->hdr_namelen <= ARC_MAXHEADER);
 
 		memset(hnbuf, '\0', sizeof hnbuf);
 		strncpy(hnbuf, h->hdr_text, h->hdr_namelen);
 		if (strcasecmp(hnbuf, ARC_AR_HDRNAME) == 0 ||
