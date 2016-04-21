$NetBSD: patch-plugins_ommysql_ommysql.c,v 1.1 2016/04/21 09:16:44 fhajny Exp $

Need netdb.h for MAXHOSTNAMELEN.

--- plugins/ommysql/ommysql.c.orig	2016-04-15 07:33:14.000000000 +0000
+++ plugins/ommysql/ommysql.c
@@ -33,6 +33,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <time.h>
+#include <netdb.h>
 #include <mysql.h>
 #include "conf.h"
 #include "syslogd-types.h"
