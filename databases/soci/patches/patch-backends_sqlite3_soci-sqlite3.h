$NetBSD: patch-backends_sqlite3_soci-sqlite3.h,v 1.1 2013/07/05 21:04:45 joerg Exp $

sqlite.h is included inside a namespace, so make sure that
the content of stdarg.h is in the default namespace.

--- backends/sqlite3/soci-sqlite3.h.orig	2013-03-22 00:48:38.000000000 +0000
+++ backends/sqlite3/soci-sqlite3.h
@@ -23,6 +23,7 @@
 # define SOCI_SQLITE3_DECL
 #endif
 
+#include <stdarg.h>
 #include <vector>
 #include "soci-backend.h"
 
