$NetBSD: patch-src_vtab__module.hh,v 1.1 2023/05/24 22:42:53 he Exp $

Fix mismatch between format and data type.

--- src/vtab_module.hh.orig	2022-09-20 04:05:51.000000000 +0000
+++ src/vtab_module.hh
@@ -456,14 +456,14 @@ struct sqlite_func_adapter<Return (*)(Ar
             if (OPT_COUNT == 0) {
                 snprintf(buffer,
                          sizeof(buffer),
-                         "%s() expects exactly %ld argument%s",
+                         "%s() expects exactly %u argument%s",
                          fd->fd_help.ht_name,
                          REQ_COUNT,
                          REQ_COUNT == 1 ? "s" : "");
             } else {
                 snprintf(buffer,
                          sizeof(buffer),
-                         "%s() expects between %ld and %ld arguments",
+                         "%s() expects between %u and %u arguments",
                          fd->fd_help.ht_name,
                          REQ_COUNT,
                          REQ_COUNT + OPT_COUNT);
