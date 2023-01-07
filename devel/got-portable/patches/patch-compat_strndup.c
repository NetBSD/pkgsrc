$NetBSD: patch-compat_strndup.c,v 1.1 2023/01/07 00:01:32 vins Exp $

Provide a declaration of strdup()

--- compat/strndup.c.orig	2022-11-08 21:21:19.000000000 +0000
+++ compat/strndup.c
@@ -22,6 +22,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifndef HAVE_STRDUP
+extern char* strdup(const char*);
+#endif
+
 char *
 strndup(const char *str, size_t maxlen)
 {
