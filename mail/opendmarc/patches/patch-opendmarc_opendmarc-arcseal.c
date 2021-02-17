$NetBSD: patch-opendmarc_opendmarc-arcseal.c,v 1.1 2021/02/17 01:49:12 manu Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcseal.c.orig	2021-02-16 23:42:14.132748160 +0100
+++ opendmarc/opendmarc-arcseal.c	2021-02-16 23:43:43.400895411 +0100
@@ -222,9 +222,13 @@
 		token_ptr = token + leading_space_len;
 		if (*token_ptr == '\0')
 			return 0;
 		tag_label = strsep(&token_ptr, "=");
+		if (token_ptr == NULL)
+			return -1;
 		tag_value = opendmarc_arcseal_strip_whitespace(token_ptr);
+		if (tag_value == NULL)
+			return -1;
 
 		tag_code = opendmarc_arcseal_convert(as_tags, tag_label);
 
 		switch (tag_code)
