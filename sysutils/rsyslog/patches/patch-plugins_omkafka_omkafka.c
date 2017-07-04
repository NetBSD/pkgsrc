$NetBSD: patch-plugins_omkafka_omkafka.c,v 1.2 2017/07/04 13:31:16 fhajny Exp $

Need strings.h for index().
O_LARGEFILE not defined on at least NetBSD.

--- plugins/omkafka/omkafka.c.orig	2017-06-27 13:40:22.000000000 +0000
+++ plugins/omkafka/omkafka.c
@@ -25,6 +25,7 @@
 #include <stdarg.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -76,6 +77,10 @@ struct kafka_params {
 	const char *val;
 };
 
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
+
 #if HAVE_ATOMIC_BUILTINS64
 static uint64 clockTopicAccess = 0;
 #else
