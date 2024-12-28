$NetBSD: patch-lib_ttyutils.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- lib/ttyutils.c.orig	2024-05-28 08:12:08.105260290 +0000
+++ lib/ttyutils.c
@@ -144,7 +144,7 @@ int get_terminal_name(const char **path,
 		*name = tty;
 	if (number) {
 		for (p = tty; p && *p; p++) {
-			if (isdigit(*p)) {
+			if (isdigit((unsigned char)*p)) {
 				*number = p;
 				break;
 			}
