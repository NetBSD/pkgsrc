$NetBSD: patch-lib_colors.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/colors.c.orig	2018-06-04 07:57:02.792445890 +0000
+++ lib/colors.c
@@ -363,7 +363,7 @@ static int cn_sequence(const char *str, 
 	*seq = NULL;
 
 	/* convert logical names like "red" to the real sequence */
-	if (*str != '\\' && isalpha(*str)) {
+	if (*str != '\\' && isalpha((unsigned char)*str)) {
 		const char *s = color_sequence_from_colorname(str);
 		*seq = strdup(s ? s : str);
 
@@ -456,7 +456,7 @@ static int colors_add_scheme(struct ul_c
 	rc = -ENOMEM;
 
 	/* convert logical name (e.g. "red") to real ESC code */
-	if (isalpha(*seq)) {
+	if (isalpha((unsigned char)*seq)) {
 		const char *s = color_sequence_from_colorname(seq);
 		char *p;
 
