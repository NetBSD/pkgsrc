$NetBSD: patch-ldb__mdb_ldb__mdb.h,v 1.1 2022/07/21 08:56:47 adam Exp $

Fix building.

--- ldb_mdb/ldb_mdb.h.orig	2022-06-14 19:58:02.000000000 +0000
+++ ldb_mdb/ldb_mdb.h
@@ -26,6 +26,9 @@
 #define _LDB_MDB_H_
 
 #include "ldb_private.h"
+#ifdef HAVE_BSD_STRTOLL
+#undef strtoull
+#endif
 #include <lmdb.h>
 
 struct lmdb_private {
