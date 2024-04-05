$NetBSD: patch-src_libgit2_transports_smart__pkt.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range for args to ctype functions.

--- src/libgit2/transports/smart_pkt.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/libgit2/transports/smart_pkt.c
@@ -451,10 +451,10 @@ static int parse_len(size_t *out, const 
 	num[PKT_LEN_SIZE] = '\0';
 
 	for (i = 0; i < PKT_LEN_SIZE; ++i) {
-		if (!isxdigit(num[i])) {
+		if (!isxdigit((unsigned char)num[i])) {
 			/* Make sure there are no special characters before passing to error message */
 			for (k = 0; k < PKT_LEN_SIZE; ++k) {
-				if(!isprint(num[k])) {
+				if(!isprint((unsigned char)num[k])) {
 					num[k] = '.';
 				}
 			}
