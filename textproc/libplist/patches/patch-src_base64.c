$NetBSD: patch-src_base64.c,v 1.1 2012/04/22 16:11:13 wiz Exp $

Non-void functions need return values.

--- src/base64.c.orig	2012-01-11 14:29:30.000000000 +0000
+++ src/base64.c
@@ -104,9 +104,9 @@ static int base64decode_block(unsigned c
 
 unsigned char *base64decode(const char *buf, size_t *size)
 {
-	if (!buf) return;
+	if (!buf) return NULL;
 	size_t len = strlen(buf);
-	if (len <= 0) return;
+	if (len <= 0) return NULL;
 	unsigned char *outbuf = (unsigned char*)malloc((len/4)*3+3);
 
 	unsigned char *line;
