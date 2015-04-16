$NetBSD: patch-storage_tokudb_ft-index_src_ydb-internal.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- storage/tokudb/ft-index/src/ydb-internal.h.orig	2015-02-13 12:07:05.000000000 +0000
+++ storage/tokudb/ft-index/src/ydb-internal.h
@@ -108,6 +108,7 @@ PATENT RIGHTS GRANT:
 #include <locktree/range_buffer.h>
 
 #include <toku_list.h>
+#include <stdarg.h>
 
 struct __toku_db_internal {
     int opened;
