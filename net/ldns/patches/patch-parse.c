$NetBSD: patch-parse.c,v 1.2 2018/02/13 15:08:11 he Exp $

Apply fix for CVE-2017-1000231, via
https://git.nlnetlabs.nl/ldns/commit/?id=c8391790

--- parse.c.orig	2014-01-10 21:04:41.000000000 +0000
+++ parse.c
@@ -118,6 +118,10 @@ ldns_fget_token_l(FILE *f, char *token, 
 			if (line_nr) {
 				*line_nr = *line_nr + 1;
 			}
+			if (limit > 0 && (i >= limit || (size_t)(t-token) >= limit)) {
+				*t = '\0';
+				return -1;
+			}
 			*t++ = ' ';
 			prev_c = c;
 			continue;
