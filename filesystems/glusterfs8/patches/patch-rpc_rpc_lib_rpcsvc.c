$NetBSD: patch-rpc_rpc_lib_rpcsvc.c,v 1.1 2023/03/12 11:55:59 js Exp $

NetBSD build fixes
From upstream https://review.gluster.org/24648

NetBSD build fixes
From upstream https://review.gluster.org/24648

--- ./rpc/rpc-lib/src/rpcsvc.c.orig	2020-06-28 02:37:34.988840145 +0200
+++ ./rpc/rpc-lib/src/rpcsvc.c	2020-06-28 02:38:41.302115459 +0200
@@ -40,8 +40,12 @@
 
 #include "xdr-rpcclnt.h"
 #include <glusterfs/glusterfs-acl.h>
 
+#ifndef PTHREAD_MUTEX_ADAPTIVE_NP
+#define PTHREAD_MUTEX_ADAPTIVE_NP PTHREAD_MUTEX_DEFAULT
+#endif
+
 static struct rpcsvc_program gluster_dump_prog;
 
 #define rpcsvc_alloc_request(svc, request)                                     \
     do {                                                                       \
