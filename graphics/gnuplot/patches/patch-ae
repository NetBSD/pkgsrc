$NetBSD: patch-ae,v 1.2 2011/02/08 13:13:41 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/plot.c.orig	2008-12-15 07:18:36.000000000 +0300
+++ src/plot.c	2009-09-14 17:22:09.000000000 +0400
@@ -118,7 +118,7 @@
 /* BSD editline
 */
 #ifdef HAVE_LIBEDITLINE
-# include <editline/readline.h>
+# include <readline/readline.h>
 #endif
 
 /* enable gnuplot history with readline */
