$NetBSD: patch-Modules_readline.c,v 1.1 2024/04/30 16:55:22 cheusov Exp $

pkgsrc buildlink framework installs libedit headers to readline/ subdirectory.

--- Modules/readline.c.orig	2024-04-30 14:54:41.228944748 +0000
+++ Modules/readline.c
@@ -29,7 +29,7 @@
 #endif
 
 #ifdef WITH_EDITLINE
-#  include <editline/readline.h>
+#  include <readline/readline.h>
 #else
 /* GNU readline definitions */
 #  undef HAVE_CONFIG_H /* Else readline/chardefs.h includes strings.h */
