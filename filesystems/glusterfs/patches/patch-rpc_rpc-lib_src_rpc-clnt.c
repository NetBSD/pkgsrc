$NetBSD: patch-rpc_rpc-lib_src_rpc-clnt.c,v 1.1 2012/12/20 21:53:20 joerg Exp $

--- rpc/rpc-lib/src/rpc-clnt.c.orig	2012-12-20 14:57:05.000000000 +0000
+++ rpc/rpc-lib/src/rpc-clnt.c
@@ -951,7 +951,7 @@ rpc_clnt_connection_deinit (rpc_clnt_con
 }
 
 
-inline int
+int
 rpc_clnt_connection_init (struct rpc_clnt *clnt, glusterfs_ctx_t *ctx,
                           dict_t *options, char *name)
 {
