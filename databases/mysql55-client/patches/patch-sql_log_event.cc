$NetBSD: patch-sql_log_event.cc,v 1.3 2013/01/03 21:23:04 adam Exp $

* Portability: include <bstring.h> if exists.

--- sql/log_event.cc.orig	2012-12-10 06:16:24.000000000 +0000
+++ sql/log_event.cc
@@ -46,6 +46,9 @@
 #include "transaction.h"
 #include <my_dir.h>
 #include "sql_show.h"    // append_identifier
+#ifdef NEEDS_BSTRING_H
+#include <bstring.h> /* defines bcmp() */
+#endif
 
 #endif /* MYSQL_CLIENT */
 
