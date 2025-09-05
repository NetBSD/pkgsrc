$NetBSD: patch-proto_bfd_bfd.h,v 1.1 2025/09/05 06:23:45 adam Exp $

Remove unused field (pthread_spinlock_t is not portable).

--- proto/bfd/bfd.h.orig	2025-09-05 05:46:36.421261181 +0000
+++ proto/bfd/bfd.h
@@ -82,7 +82,6 @@ struct bfd_proto
 {
   struct proto p;
 
-  pthread_spinlock_t lock;
 
   pool *tpool;
 
