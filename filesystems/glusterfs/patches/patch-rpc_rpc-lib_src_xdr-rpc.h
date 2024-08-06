$NetBSD: patch-rpc_rpc-lib_src_xdr-rpc.h,v 1.1 2024/08/06 18:51:19 riastradh Exp $

Fix rpc type printf formats for NetBSD.

--- rpc/rpc-lib/src/xdr-rpc.h.orig	2023-04-06 09:01:24.771967553 +0000
+++ rpc/rpc-lib/src/xdr-rpc.h
@@ -76,7 +76,7 @@ xdr_to_auth_unix_cred(char *msgbuf, int 
 #define rpc_call_verf_len(call)                                                \
     (rpc_opaque_auth_len((&(call)->ru.RM_cmb.cb_verf)))
 
-#if defined(GF_DARWIN_HOST_OS) || !defined(HAVE_RPC_RPC_H)
+#if defined(GF_DARWIN_HOST_OS) || defined(__NetBSD__) || !defined(HAVE_RPC_RPC_H)
 #define GF_PRI_RPC_XID PRIu32
 #define GF_PRI_RPC_VERSION PRIu32
 #define GF_PRI_RPC_PROG_ID PRIu32
