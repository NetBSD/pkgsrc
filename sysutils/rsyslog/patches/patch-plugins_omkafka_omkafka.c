$NetBSD: patch-plugins_omkafka_omkafka.c,v 1.1 2017/05/22 23:43:00 joerg Exp $

--- plugins/omkafka/omkafka.c.orig	2017-05-21 19:04:23.931288632 +0000
+++ plugins/omkafka/omkafka.c
@@ -29,6 +29,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <pthread.h>
+#include <sys/stat.h>
 #include <sys/uio.h>
 #include <librdkafka/rdkafka.h>
 #include "syslogd-types.h"
@@ -67,6 +68,10 @@ struct kafka_params {
 	const char *val;
 };
 
+#ifndef O_LARGEFILE
+#define O_LARGEFILE 0
+#endif
+
 #if HAVE_ATOMIC_BUILTINS64
 static uint64 clockTopicAccess = 0;
 #else
