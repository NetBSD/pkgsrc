$NetBSD: patch-opendmarc_opendmarc-arcares.c,v 1.1 2021/02/17 01:49:12 manu Exp $

Avoid handling a NULL pointer when parsing a malformed header

--- opendmarc/opendmarc-arcares.c.orig	2021-02-16 16:33:34.454279528 +0000
+++ opendmarc/opendmarc-arcares.c	2021-02-16 16:35:14.240570993 +0000
@@ -324,8 +324,10 @@
 		if (*token_ptr == '\0')
 			return 0;
 		tag_label = strsep(&token_ptr, "=");
+		if (token_ptr == NULL)
+			return -1;
 		tag_value = opendmarc_arcares_strip_whitespace(token_ptr);
 		tag_code = opendmarc_arcares_convert(aar_arc_tags, tag_label);
 
 		switch (tag_code)
 		{
