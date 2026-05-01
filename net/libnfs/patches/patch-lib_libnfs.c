$NetBSD: patch-lib_libnfs.c,v 1.1 2026/05/01 19:43:30 vins Exp $

Improve portability: Use of pthread_threadid_np(2) or gettid(2) is never a
good idea, especially when pthread_equal(3) suffices.

--- lib/libnfs.c.orig	2025-11-14 13:38:41.562942211 +0000
+++ lib/libnfs.c
@@ -229,7 +229,7 @@ nfs_get_error(struct nfs_context *nfs)
                 struct nfs_thread_context *ntc;
 
                 for(ntc = nfs->nfsi->thread_ctx; ntc; ntc = ntc->next) {
-                        if (nfs_mt_get_tid() == ntc->tid) {
+                        if (nfs_mt_equal(nfs_mt_get_tid(), ntc->tid)) {
                                 nfs = &ntc->nfs;
                                 break;
                         }
