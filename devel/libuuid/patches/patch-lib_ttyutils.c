$NetBSD: patch-lib_ttyutils.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/ttyutils.c.orig	2018-07-11 13:34:54.228003727 +0000
+++ lib/ttyutils.c
@@ -104,7 +104,7 @@ int get_terminal_name(const char **path,
 		*name = tty;
 	if (number) {
 		for (p = tty; p && *p; p++) {
-			if (isdigit(*p)) {
+			if (isdigit((unsigned char)*p)) {
 				*number = p;
 				break;
 			}
