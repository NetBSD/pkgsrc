$NetBSD: patch-pbx_pbx__config.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- pbx/pbx_config.c.orig	2018-05-07 17:17:05.322793470 +0000
+++ pbx/pbx_config.c
@@ -237,7 +237,7 @@ static const char *skip_words(const char
 {
 	int in_blank = 0;
 	for (;n && *p; p++) {
-		if (isblank(*p) /* XXX order is important */ && !in_blank) {
+		if (isblank((unsigned char)*p) /* XXX order is important */ && !in_blank) {
 			n--;	/* one word is gone */
 			in_blank = 1;
 		} else if (/* !is_blank(*p), we know already, && */ in_blank) {
@@ -447,7 +447,7 @@ static char *handle_cli_dialplan_remove_
 		if (!strcmp("hint", c))
 			removing_priority = PRIORITY_HINT;
 		else {
-			while (*c && isdigit(*c))
+			while (*c && isdigit((unsigned char)*c))
 				c++;
 			if (*c) { /* non-digit in string */
 				ast_cli(a->fd, "Invalid priority '%s'\n", a->argv[4]);
