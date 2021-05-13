$NetBSD: patch-include_tables__contained__in.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* some systems have ffsll in strings.h
* for systems that don't have ffsll, use the provided version

--- include/tables_contained_in.h.orig	2019-12-09 19:53:17.000000000 +0000
+++ include/tables_contained_in.h
@@ -26,6 +26,16 @@
 
 #include <string.h>
 
+#include "my_config.h"
+
+#ifdef HAVE_STRINGS_H
+#include <strings.h>
+#endif
+
+#ifndef HAVE_FFSLL
+int ffsll(longlong);
+#endif
+
 #include "my_inttypes.h"
 #include "sql/sql_optimizer.h"
 
