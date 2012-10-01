$NetBSD: patch-client_mysqlbinlog.cc,v 1.2 2012/10/01 15:54:40 adam Exp $

* Portability: include <bstring.h> if exists.

--- client/mysqlbinlog.cc.orig	2012-08-29 08:50:46.000000000 +0000
+++ client/mysqlbinlog.cc
@@ -38,6 +38,9 @@
 #include "sql_common.h"
 #include "my_dir.h"
 #include <welcome_copyright_notice.h> // ORACLE_WELCOME_COPYRIGHT_NOTICE
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
 
 #define BIN_LOG_HEADER_SIZE	4
 #define PROBE_HEADER_LEN	(EVENT_LEN_OFFSET+4)
