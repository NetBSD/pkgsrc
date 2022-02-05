$NetBSD: patch-include_netbsd_hax__netbsd.h,v 1.1 2022/02/05 03:25:56 ryoon Exp $

* Upstream master branch resolves this problem in another way.
  Please remove this in next update (after 7.7.0).

--- include/netbsd/hax_netbsd.h.orig	2021-05-24 08:15:13.000000000 +0000
+++ include/netbsd/hax_netbsd.h
@@ -34,6 +34,9 @@
 
 #define HAX_RAM_ENTRY_SIZE 0x4000000
 
+#define min(a,b)  (((a)<(b))?(a):(b))
+#define max(a,b)  (((a)>(b))?(a):(b))
+
 hax_spinlock *hax_spinlock_alloc_init(void);
 void hax_spinlock_free(hax_spinlock *lock);
 void hax_spin_lock(hax_spinlock *lock);
