$NetBSD: patch-src_plot.c,v 1.2 2024/06/05 13:56:14 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/plot.c.orig	2023-12-18 23:28:58.000000000 +0000
+++ src/plot.c
@@ -81,7 +81,7 @@
 /* BSD editline
 */
 #ifdef HAVE_LIBEDITLINE
-#  include <editline/readline.h>
+#  include <readline/readline.h>
 #  ifdef GNUPLOT_HISTORY
 #    include <histedit.h>
 #  endif
