$NetBSD: patch-opendmarc_opendmarc-arcseal.c,v 1.3 2022/05/12 13:49:28 jperkin Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcseal.c.orig	2021-12-20 06:40:37.000000000 +0000
+++ opendmarc/opendmarc-arcseal.c
@@ -167,7 +167,11 @@ opendmarc_arcseal_parse(u_char *hdr, str
 		if (*token_ptr == '\0')
 			return 0;
 		tag_label = strsep(&token_ptr, "=");
+		if (token_ptr == NULL)
+			return -1;
 		tag_value = opendmarc_arcseal_strip_whitespace(token_ptr);
+		if (tag_value == NULL)
+			return -1;
 
 		tag_code = opendmarc_arcseal_convert(as_tags, tag_label);
 
