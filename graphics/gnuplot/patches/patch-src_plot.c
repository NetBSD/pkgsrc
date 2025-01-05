$NetBSD: patch-src_plot.c,v 1.3 2025/01/05 09:08:55 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/plot.c.orig	2024-12-20 00:26:46.000000000 +0000
+++ src/plot.c
@@ -81,7 +81,7 @@
 /* BSD editline
 */
 #ifdef HAVE_LIBEDITLINE
-#  include <editline/readline.h>
+#  include <readline/readline.h>
 #  include <histedit.h>
 #endif
 
