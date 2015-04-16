$NetBSD: patch-client_mysqlbinlog.cc,v 1.1 2015/04/16 20:20:15 ryoon Exp $

Portability: include <bstring.h> if exists.

--- client/mysqlbinlog.cc.orig	2015-02-13 12:07:00.000000000 +0000
+++ client/mysqlbinlog.cc
@@ -40,6 +40,9 @@
 #include "sql_common.h"
 #include "my_dir.h"
 #include <welcome_copyright_notice.h> // ORACLE_WELCOME_COPYRIGHT_NOTICE
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bzero() */
+#endif
 
 
 #include "sql_string.h"   // needed for Rpl_filter
