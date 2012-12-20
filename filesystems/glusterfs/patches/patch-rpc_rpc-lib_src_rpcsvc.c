$NetBSD: patch-rpc_rpc-lib_src_rpcsvc.c,v 1.1 2012/12/20 21:53:20 joerg Exp $

--- rpc/rpc-lib/src/rpcsvc.c.orig	2012-12-20 14:55:50.000000000 +0000
+++ rpc/rpc-lib/src/rpcsvc.c
@@ -220,7 +220,7 @@ err:
 /* this procedure can only pass 4 arguments to registered notifyfn. To send more
  * arguments call wrapper->notify directly.
  */
-inline void
+void
 rpcsvc_program_notify (rpcsvc_listener_t *listener, rpcsvc_event_t event,
                        void *data)
 {
@@ -243,7 +243,7 @@ out:
 }
 
 
-inline int
+int
 rpcsvc_accept (rpcsvc_t *svc, rpc_transport_t *listen_trans,
                rpc_transport_t *new_trans)
 {
@@ -687,7 +687,7 @@ err:
         return txrecord;
 }
 
-inline int
+int
 rpcsvc_get_callid (rpcsvc_t *rpc)
 {
         return GF_UNIVERSAL_ANSWER;
@@ -873,7 +873,7 @@ out:
         return ret;
 }
 
-inline int
+int
 rpcsvc_transport_submit (rpc_transport_t *trans, struct iovec *hdrvec,
                          int hdrcount, struct iovec *proghdr, int proghdrcount,
                          struct iovec *progpayload, int progpayloadcount,
@@ -1120,7 +1120,7 @@ rpcsvc_error_reply (rpcsvc_request_t *re
 
 
 /* Register the program with the local portmapper service. */
-inline int
+int
 rpcsvc_program_register_portmap (rpcsvc_program_t *newprog, uint32_t port)
 {
         int                ret   = 0;
@@ -1142,7 +1142,7 @@ out:
 }
 
 
-inline int
+int
 rpcsvc_program_unregister_portmap (rpcsvc_program_t *prog)
 {
         int ret = 0;
@@ -1320,7 +1320,7 @@ out:
 }
 
 
-inline int
+int
 rpcsvc_transport_peername (rpc_transport_t *trans, char *hostname, int hostlen)
 {
         if (!trans) {
@@ -1331,7 +1331,7 @@ rpcsvc_transport_peername (rpc_transport
 }
 
 
-inline int
+int
 rpcsvc_transport_peeraddr (rpc_transport_t *trans, char *addrstr, int addrlen,
                            struct sockaddr_storage *sa, socklen_t sasize)
 {
@@ -1583,7 +1583,7 @@ out:
 }
 
 
-inline int
+int
 rpcsvc_program_register (rpcsvc_t *svc, rpcsvc_program_t *program)
 {
         int               ret                = -1;
