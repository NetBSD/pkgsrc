$NetBSD: patch-ad,v 1.1 2009/09/14 18:52:03 asau Exp $

NetBSD editline keeps header files in "readline", not "editline".
Same applies to DragonFly.

--- src/readline.h.orig	2008-12-15 07:18:36.000000000 +0300
+++ src/readline.h	2009-09-14 17:16:14.000000000 +0400
@@ -51,7 +51,7 @@
 # include <readline/readline.h>
 #endif
 #if defined(HAVE_LIBEDITLINE)
-# include <editline/readline.h>
+# include <readline/readline.h>
 #endif
 
 #if defined(HAVE_LIBEDITLINE)
