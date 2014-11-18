$NetBSD: patch-rpc_rpc-lib_src_rpcsvc.c,v 1.3 2014/11/18 14:38:15 manu Exp $

Shut up log-filling message

--- rpc/rpc-lib/src/rpcsvc.c.orig	2014-11-04 14:27:15.000000000 +0100
+++ rpc/rpc-lib/src/rpcsvc.c	2014-11-04 14:28:46.000000000 +0100
@@ -611,9 +611,9 @@
                 goto err_reply;
 
         if (0 == svc->allow_insecure && unprivileged && !actor->unprivileged) {
                         /* Non-privileged user, fail request */
-                        gf_log (GF_RPCSVC, GF_LOG_ERROR,
+                        gf_log (GF_RPCSVC, GF_LOG_DEBUG,
                                 "Request received from non-"
                                 "privileged port. Failing request");
                         rpcsvc_request_destroy (req);
                         return -1;
