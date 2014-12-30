$NetBSD: patch-xen_include_asm-arm_spinlock.h,v 1.1 2014/12/30 08:15:01 spz Exp $

from XSA-114:
switch to write-biased r/w locks

This is to improve fairness: A permanent flow of read acquires can
otherwise lock out eventual writers indefinitely.

This is XSA-114 / CVE-2014-9065.

--- xen/include/asm-arm/spinlock.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ xen/include/asm-arm/spinlock.h
@@ -55,84 +55,6 @@ static always_inline int _raw_spin_trylo
     }
 }
 
-typedef struct {
-    volatile unsigned int lock;
-} raw_rwlock_t;
-
-#define _RAW_RW_LOCK_UNLOCKED { 0 }
-
-static always_inline int _raw_read_trylock(raw_rwlock_t *rw)
-{
-    unsigned long tmp, tmp2 = 1;
-
-    __asm__ __volatile__(
-"1: ldrex   %0, [%2]\n"
-"   adds    %0, %0, #1\n"
-"   strexpl %1, %0, [%2]\n"
-    : "=&r" (tmp), "+r" (tmp2)
-    : "r" (&rw->lock)
-    : "cc");
-
-    smp_mb();
-    return tmp2 == 0;
-}
-
-static always_inline int _raw_write_trylock(raw_rwlock_t *rw)
-{
-    unsigned long tmp;
-
-    __asm__ __volatile__(
-"1: ldrex   %0, [%1]\n"
-"   teq     %0, #0\n"
-"   strexeq %0, %2, [%1]"
-    : "=&r" (tmp)
-    : "r" (&rw->lock), "r" (0x80000000)
-    : "cc");
-
-    if (tmp == 0) {
-        smp_mb();
-        return 1;
-    } else {
-        return 0;
-    }
-}
-
-static inline void _raw_read_unlock(raw_rwlock_t *rw)
-{
-    unsigned long tmp, tmp2;
-
-    smp_mb();
-
-    __asm__ __volatile__(
-"1: ldrex   %0, [%2]\n"
-"   sub     %0, %0, #1\n"
-"   strex   %1, %0, [%2]\n"
-"   teq     %1, #0\n"
-"   bne     1b"
-    : "=&r" (tmp), "=&r" (tmp2)
-    : "r" (&rw->lock)
-    : "cc");
-
-    if (tmp == 0)
-        dsb_sev();
-}
-
-static inline void _raw_write_unlock(raw_rwlock_t *rw)
-{
-    smp_mb();
-
-    __asm__ __volatile__(
-    "str    %1, [%0]\n"
-    :
-    : "r" (&rw->lock), "r" (0)
-    : "cc");
-
-    dsb_sev();
-}
-
-#define _raw_rw_is_locked(x) ((x)->lock != 0)
-#define _raw_rw_is_write_locked(x) ((x)->lock == 0x80000000)
-
 #endif /* __ASM_SPINLOCK_H */
 /*
  * Local variables:
