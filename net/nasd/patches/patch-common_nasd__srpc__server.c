$NetBSD: patch-common_nasd__srpc__server.c,v 1.1 2013/09/17 21:14:37 joerg Exp $

--- common/nasd_srpc_server.c.orig	2013-09-17 19:56:59.000000000 +0000
+++ common/nasd_srpc_server.c
@@ -198,7 +198,7 @@ nasd_srpc_call_enable_pipes(
 /*
  * call with conn lock held
  */
-void NASD_INLINE
+static void NASD_INLINE
 nasd_srpc_server_relock_change_handle(
   nasd_srpc_listener_t     *listener,
   nasd_srpc_conn_t         *conn,
