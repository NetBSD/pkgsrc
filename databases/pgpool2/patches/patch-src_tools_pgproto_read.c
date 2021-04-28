$NetBSD: patch-src_tools_pgproto_read.c,v 1.1 2021/04/28 09:18:55 wiz Exp $

--- src/tools/pgproto/read.c.orig	2021-04-24 00:48:42.306544222 +0300
+++ src/tools/pgproto/read.c	2021-04-24 00:49:09.010194923 +0300
@@ -23,6 +23,7 @@
 #include <string.h>
 #include <errno.h>
 #include <arpa/inet.h>
+#include <sys/time.h>
 #include "pgproto/fe_memutils.h"
 #include <libpq-fe.h>
 #include "pgproto/read.h"
