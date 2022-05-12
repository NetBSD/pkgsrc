$NetBSD: patch-opendmarc_opendmarc-arcares.c,v 1.3 2022/05/12 13:49:28 jperkin Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcares.c.orig	2021-12-20 06:40:37.000000000 +0000
+++ opendmarc/opendmarc-arcares.c
@@ -266,6 +266,8 @@ opendmarc_arcares_arc_parse (u_char *hdr
 		if (*token_ptr == '\0')
 			return 0;
 		tag_label = strsep(&token_ptr, "=");
+		if (token_ptr == NULL)
+			return -1;
 		tag_value = opendmarc_arcares_strip_whitespace(token_ptr);
 		tag_code = opendmarc_arcares_convert(aar_arc_tags, tag_label);
 
