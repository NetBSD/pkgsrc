$NetBSD: patch-lib_ldb_ldb__mdb_ldb__mdb.c,v 1.2 2018/12/22 01:13:52 adam Exp $

Some systems do not define EBADE.

--- lib/ldb/ldb_mdb/ldb_mdb.c.orig	2018-07-12 08:23:36.000000000 +0000
+++ lib/ldb/ldb_mdb/ldb_mdb.c
@@ -40,7 +40,9 @@ int ldb_mdb_err_map(int lmdb_err)
 		return LDB_SUCCESS;
 	case EIO:
 		return LDB_ERR_OPERATIONS_ERROR;
+#ifdef EBADE
 	case EBADE:
+#endif
 	case MDB_INCOMPATIBLE:
 	case MDB_CORRUPTED:
 	case MDB_INVALID:
