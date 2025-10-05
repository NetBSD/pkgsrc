$NetBSD: patch-libpurple_util.c,v 1.1 2025/10/05 16:01:16 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/util.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/util.c	2025-10-05 15:18:10.643015312 +0200
@@ -215,11 +215,11 @@
 		else
 			accumulator <<= 4;
 
-		if (isdigit(str[i]))
+		if (isdigit((unsigned char)str[i]))
 			accumulator |= str[i] - 48;
 		else
 		{
-			switch(tolower(str[i]))
+			switch(tolower((unsigned char)str[i]))
 			{
 				case 'a':  accumulator |= 10;  break;
 				case 'b':  accumulator |= 11;  break;
@@ -310,8 +310,8 @@
 				n -= 1;
 				p += 1;
 			} else if (p[1] && p[2]) {
-				char *nibble1 = strchr(xdigits, tolower(p[1]));
-				char *nibble2 = strchr(xdigits, tolower(p[2]));
+				char *nibble1 = strchr(xdigits, tolower((unsigned char)p[1]));
+				char *nibble2 = strchr(xdigits, tolower((unsigned char)p[2]));
 				if (nibble1 && nibble2) { /* 5.1 #1 */
 					*n = ((nibble1 - xdigits) << 4) | (nibble2 - xdigits);
 					p += 2;
@@ -362,11 +362,11 @@
 
 	/* token can be any CHAR (supposedly ISO8859-1/ISO2022), not just ASCII */
 	#define token_char_p(c) \
-		(c != ' ' && !iscntrl(c) && !strchr("()<>@,;:\"/[]?.=", c))
+		(c != ' ' && !iscntrl((unsigned char)c) && !strchr("()<>@,;:\"/[]?.=", c))
 
 	/* But encoded-text must be ASCII; alas, isascii() may not exist */
 	#define encoded_text_char_p(c) \
-		((c & 0x80) == 0 && c != '?' && c != ' ' && isgraph(c))
+		((c & 0x80) == 0 && c != '?' && c != ' ' && isgraph((unsigned char)c))
 
 	g_return_val_if_fail(str != NULL, NULL);
 
@@ -4588,7 +4588,7 @@
 	*/
 	while (p) {
 		if (*p != '#') {
-			while (isspace(*p))
+			while (isspace((unsigned char)*p))
 				p++;
 
 			q = p;
@@ -4597,7 +4597,7 @@
 
 			if (q > p) {
 				q--;
-				while (q > p && isspace(*q))
+				while (q > p && isspace((unsigned char)*q))
 					q--;
 
 				retval = (gchar*)g_malloc (q - p + 2);
@@ -5124,7 +5124,7 @@
 	if (act && purple_strequal(protocol, "prpl-oscar")) {
 		int i;
 		for (i = 0; act[i] != '\0'; i++)
-			if (!isdigit(act[i]))
+			if (!isdigit((unsigned char)act[i]))
 				return "prpl-aim";
 		return "prpl-icq";
 	}
