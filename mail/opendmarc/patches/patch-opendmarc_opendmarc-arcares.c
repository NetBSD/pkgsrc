$NetBSD: patch-opendmarc_opendmarc-arcares.c,v 1.2 2021/05/27 16:52:00 manu Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcares.c.orig	2021-04-30 18:34:43.000000000 +0200
+++ opendmarc/opendmarc-arcares.c	2021-05-27 10:30:03.036068852 +0200
@@ -265,8 +265,10 @@
 		token_ptr = token + leading_space_len;
 		if (*token_ptr == '\0')
 			return 0;
 		tag_label = strsep(&token_ptr, "=");
+		if (token_ptr == NULL)
+			return -1;
 		tag_value = opendmarc_arcares_strip_whitespace(token_ptr);
 		tag_code = opendmarc_arcares_convert(aar_arc_tags, tag_label);
 
 		switch (tag_code)
