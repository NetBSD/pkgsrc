$NetBSD: patch-lib_libnfs-sync.c,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Use of pthread_threadid_np(2) or gettid(2) is never a
good idea, especially when pthread_equal(3) suffices.

--- lib/libnfs-sync.c.orig	2025-11-14 13:37:44.606850244 +0000
+++ lib/libnfs-sync.c
@@ -133,7 +133,7 @@ nfs_init_cb_data(struct nfs_context **nf
                 struct nfs_thread_context *ntc;
 
                 for(ntc = (*nfs)->nfsi->thread_ctx; ntc; ntc = ntc->next) {
-                        if (nfs_mt_get_tid() == ntc->tid) {
+                        if (nfs_mt_equal(nfs_mt_get_tid(), ntc->tid)) {
                                 break;
                         }
                 }
