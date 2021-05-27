$NetBSD: patch-opendmarc_opendmarc-arcseal.c,v 1.2 2021/05/27 16:52:00 manu Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcseal.c.orig	2021-04-30 18:34:43.000000000 +0200
+++ opendmarc/opendmarc-arcseal.c	2021-05-27 10:31:21.308140659 +0200
@@ -166,9 +166,13 @@
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
