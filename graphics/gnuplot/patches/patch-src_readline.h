$NetBSD: patch-src_readline.h,v 1.1 2017/11/03 15:00:10 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/readline.h.orig	2016-05-26 01:10:06.000000000 +0000
+++ src/readline.h
@@ -51,7 +51,7 @@
 # include <readline/readline.h>
 
 #elif defined(HAVE_LIBEDITLINE)
-# include <editline/readline.h>
+# include <readline/readline.h>
 #endif
 
 #if defined(READLINE)
