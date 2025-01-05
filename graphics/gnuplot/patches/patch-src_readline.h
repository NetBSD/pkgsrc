$NetBSD: patch-src_readline.h,v 1.2 2025/01/05 09:08:55 adam Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/readline.h.orig	2024-10-29 17:28:55.000000000 +0000
+++ src/readline.h
@@ -40,7 +40,7 @@
 # include <readline/readline.h>
 
 #elif defined(HAVE_LIBEDITLINE)
-# include <editline/readline.h>
+# include <readline/readline.h>
 # include <histedit.h>
 #endif
 
