$NetBSD: patch-tools_libs_xenstore_xenstored_control.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

error: array subscript has type 'char' [-Werror=char-subscripts]

--- tools/xenstore/xenstored_control.c.orig	2021-04-17 22:20:28.658953461 +0200
+++ tools/xenstore/xenstored_control.c	2021-04-17 22:20:41.265121523 +0200
@@ -601,7 +601,7 @@
 	if (lu_status->cmdline) {
 		argc = 4;   /* At least one arg + progname + "-U" + NULL. */
 		for (i = 0; lu_status->cmdline[i]; i++)
-			if (isspace(lu_status->cmdline[i]))
+			if (isspace((unsigned char)lu_status->cmdline[i]))
 				argc++;
 		argv = talloc_array(ctx, char *, argc);
 		if (!argv)
