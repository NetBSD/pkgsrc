$NetBSD: patch-src_plot.c,v 1.1 2017/11/03 15:00:10 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/plot.c.orig	2017-06-02 01:43:38.000000000 +0000
+++ src/plot.c
@@ -107,7 +107,7 @@ extern smg$create_key_table();
 /* BSD editline
 */
 #ifdef HAVE_LIBEDITLINE
-# include <editline/readline.h>
+# include <readline/readline.h>
 #endif
 
 /* enable gnuplot history with readline */
