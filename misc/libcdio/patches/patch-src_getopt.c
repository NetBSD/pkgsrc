$NetBSD: patch-src_getopt.c,v 1.1 2025/07/10 14:57:46 jperkin Exp $

Use HAVE_ALLOCA_H.

--- src/getopt.c.orig	2025-07-10 14:56:09.167885298 +0000
+++ src/getopt.c
@@ -29,6 +29,10 @@
 # include <config.h>
 #endif
 
+#ifdef HAVE_ALLOCA_H
+# include <alloca.h>
+#endif
+
 #ifdef HAVE_STDLIB_H
 # include <stdlib.h>
 #endif
