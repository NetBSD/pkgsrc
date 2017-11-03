$NetBSD: patch-src_gp__hist.h,v 1.1 2017/11/03 15:00:10 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.
FreeBSD requires additional header file to get access to history.

--- src/gp_hist.h.orig	2016-05-26 01:10:06.000000000 +0000
+++ src/gp_hist.h
@@ -57,7 +57,10 @@ extern TBOOLEAN history_full;
 /* NetBSD editline / WinEditLine
  * (almost) compatible readline replacement
  */
-# include <editline/readline.h>
+# if defined(__FreeBSD__)
+#   include <readline/history.h>
+# endif
+# include <readline/readline.h>
 
 
 #elif defined(READLINE)
