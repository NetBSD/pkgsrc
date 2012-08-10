$NetBSD: patch-ac,v 1.2 2012/08/10 15:14:54 drochner Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/gp_hist.h.orig	2011-02-21 07:56:57.000000000 +0000
+++ src/gp_hist.h
@@ -70,7 +70,7 @@ extern long int gnuplot_history_size;
  * (almost) compatible readline replacement
  */
 #if defined(HAVE_LIBEDITLINE)
-# include <editline/readline.h>
+# include <readline/readline.h>
 #endif
 
 #if defined(READLINE) && !defined(HAVE_LIBREADLINE) && !defined(HAVE_LIBEDITLINE)
