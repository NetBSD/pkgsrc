$NetBSD: patch-mustach.c,v 1.1 2019/12/25 17:34:32 sjmulder Exp $

Include alloca.h on Solaris-likes to fix the build.

--- mustach.c.orig	2019-09-19 08:20:36.000000000 +0000
+++ mustach.c
@@ -24,6 +24,9 @@
 #include <string.h>
 #include <errno.h>
 #include <ctype.h>
+#ifdef __sun
+# include <alloca.h>
+#endif
 
 #include "mustach.h"
 
