$NetBSD: patch-pidgin_gtkimhtml.c,v 1.1 2025/10/05 07:39:53 wiz Exp $

Fix -Wchar-subscripts

The code isspace(*(c - 1)) below actually later triggers a segfault in
NetBSD-11 when passed a non-ASCII char in the range [0x80-0xff].

--- pidgin/gtkimhtml.c~	2024-09-17 10:52:23.000000000 +0200
+++ pidgin/gtkimhtml.c	2025-10-05 04:44:34.643159904 +0200
@@ -3095,7 +3095,7 @@
 							} else if (*size == '-') {
 								sscanf (size + 1, "%hd", &font->size);
 								font->size = MAX (0, 3 - font->size);
-							} else if (isdigit (*size)) {
+							} else if (isdigit ((unsigned char)*size)) {
 								sscanf (size, "%hd", &font->size);
 							}
 							if (font->size > 100)
@@ -3512,9 +3512,9 @@
 			}
 			c++;
 			pos++;
-		} else if ((pos == 0 || wpos == 0 || isspace(*(c - 1))) &&
+		} else if ((pos == 0 || wpos == 0 || isspace((unsigned char)*(c - 1))) &&
 		           (len_protocol = gtk_imhtml_is_protocol(c)) > 0 &&
-				   c[len_protocol] && !isspace(c[len_protocol]) &&
+				   c[len_protocol] && !isspace((unsigned char)c[len_protocol]) &&
 				   (c[len_protocol] != '<' || !gtk_imhtml_is_tag(c + 1, NULL, NULL, NULL))) {
 			br = FALSE;
 			if (wpos > 0) {
