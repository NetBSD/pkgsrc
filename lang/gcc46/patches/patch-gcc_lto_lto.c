$NetBSD: patch-gcc_lto_lto.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/lto/lto.c.orig	2012-04-23 12:44:46.000000000 +0000
+++ gcc/lto/lto.c
@@ -2486,4 +2486,10 @@ lto_main (void)
     }
 }
 
+const char *
+fname_as_string(int pretty_p)
+{
+	return NULL;
+}
+
 #include "gt-lto-lto.h"
