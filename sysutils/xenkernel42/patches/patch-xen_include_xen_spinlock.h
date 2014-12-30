$NetBSD: patch-xen_include_xen_spinlock.h,v 1.1 2014/12/30 08:15:01 spz Exp $

from XSA-114:
switch to write-biased r/w locks

This is to improve fairness: A permanent flow of read acquires can
otherwise lock out eventual writers indefinitely.

This is XSA-114 / CVE-2014-9065.

--- xen/include/xen/spinlock.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ xen/include/xen/spinlock.h
@@ -141,11 +141,13 @@ typedef struct spinlock {
 #define spin_lock_init(l) (*(l) = (spinlock_t)SPIN_LOCK_UNLOCKED)
 
 typedef struct {
-    raw_rwlock_t raw;
+    volatile uint32_t lock;
     struct lock_debug debug;
 } rwlock_t;
 
-#define RW_LOCK_UNLOCKED { _RAW_RW_LOCK_UNLOCKED, _LOCK_DEBUG }
+#define RW_WRITE_FLAG (1u<<31)
+
+#define RW_LOCK_UNLOCKED { 0, _LOCK_DEBUG }
 #define DEFINE_RWLOCK(l) rwlock_t l = RW_LOCK_UNLOCKED
 #define rwlock_init(l) (*(l) = (rwlock_t)RW_LOCK_UNLOCKED)
 
