$NetBSD: patch-plugins_ompgsql_ompgsql.c,v 1.1 2016/04/21 09:16:44 fhajny Exp $

Need netdb.h for MAXHOSTNAMELEN.

--- plugins/ompgsql/ompgsql.c.orig	2016-04-15 07:33:14.000000000 +0000
+++ plugins/ompgsql/ompgsql.c
@@ -39,6 +39,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <time.h>
+#include <netdb.h>
 #include <libpq-fe.h>
 #include "conf.h"
 #include "syslogd-types.h"
