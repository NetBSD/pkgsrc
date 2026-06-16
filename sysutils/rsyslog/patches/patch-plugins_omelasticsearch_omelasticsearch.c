$NetBSD: patch-plugins_omelasticsearch_omelasticsearch.c,v 1.3 2026/06/16 17:34:55 nia Exp $

It's not just FreeBSD that needs <unistd.h> for write(2) and
close(2). The Standard demands that we must include it.

Fixes the build of rsyslog-elasticsearch with more recent GCC
versions, which don't like implicit function declarations.

--- plugins/omelasticsearch/omelasticsearch.c.orig	2026-06-16 17:27:35.355077332 +0000
+++ plugins/omelasticsearch/omelasticsearch.c
@@ -38,9 +38,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#if defined(__FreeBSD__)
 #include <unistd.h>
-#endif
 #include <json.h>
 #include "conf.h"
 #include "syslogd-types.h"
