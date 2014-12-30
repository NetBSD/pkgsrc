$NetBSD: patch-xen_common_spinlock.c,v 1.1 2014/12/30 08:15:01 spz Exp $

from XSA-114:
switch to write-biased r/w locks

This is to improve fairness: A permanent flow of read acquires can
otherwise lock out eventual writers indefinitely.

This is XSA-114 / CVE-2014-9065.

--- xen/common/spinlock.c.orig	2014-09-02 06:22:57.000000000 +0000
+++ xen/common/spinlock.c
@@ -271,112 +271,151 @@ void _spin_unlock_recursive(spinlock_t *
 
 void _read_lock(rwlock_t *lock)
 {
+    uint32_t x;
+
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_read_trylock(&lock->raw)) )
-    {
-        while ( likely(_raw_rw_is_write_locked(&lock->raw)) )
+    do {
+        while ( (x = lock->lock) & RW_WRITE_FLAG )
             cpu_relax();
-    }
+    } while ( cmpxchg(&lock->lock, x, x+1) != x );
     preempt_disable();
 }
 
 void _read_lock_irq(rwlock_t *lock)
 {
+    uint32_t x;
+
     ASSERT(local_irq_is_enabled());
     local_irq_disable();
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_read_trylock(&lock->raw)) )
-    {
-        local_irq_enable();
-        while ( likely(_raw_rw_is_write_locked(&lock->raw)) )
-            cpu_relax();
-        local_irq_disable();
-    }
+    do {
+        if ( (x = lock->lock) & RW_WRITE_FLAG )
+        {
+            local_irq_enable();
+            while ( (x = lock->lock) & RW_WRITE_FLAG )
+                cpu_relax();
+            local_irq_disable();
+        }
+    } while ( cmpxchg(&lock->lock, x, x+1) != x );
     preempt_disable();
 }
 
 unsigned long _read_lock_irqsave(rwlock_t *lock)
 {
+    uint32_t x;
     unsigned long flags;
+
     local_irq_save(flags);
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_read_trylock(&lock->raw)) )
-    {
-        local_irq_restore(flags);
-        while ( likely(_raw_rw_is_write_locked(&lock->raw)) )
-            cpu_relax();
-        local_irq_save(flags);
-    }
+    do {
+        if ( (x = lock->lock) & RW_WRITE_FLAG )
+        {
+            local_irq_restore(flags);
+            while ( (x = lock->lock) & RW_WRITE_FLAG )
+                cpu_relax();
+            local_irq_save(flags);
+        }
+    } while ( cmpxchg(&lock->lock, x, x+1) != x );
     preempt_disable();
     return flags;
 }
 
 int _read_trylock(rwlock_t *lock)
 {
+    uint32_t x;
+
     check_lock(&lock->debug);
-    if ( !_raw_read_trylock(&lock->raw) )
-        return 0;
+    do {
+        if ( (x = lock->lock) & RW_WRITE_FLAG )
+            return 0;
+    } while ( cmpxchg(&lock->lock, x, x+1) != x );
     preempt_disable();
     return 1;
 }
 
 void _read_unlock(rwlock_t *lock)
 {
+    uint32_t x, y;
+
     preempt_enable();
-    _raw_read_unlock(&lock->raw);
+    x = lock->lock;
+    while ( (y = cmpxchg(&lock->lock, x, x-1)) != x )
+        x = y;
 }
 
 void _read_unlock_irq(rwlock_t *lock)
 {
-    preempt_enable();
-    _raw_read_unlock(&lock->raw);
+    _read_unlock(lock);
     local_irq_enable();
 }
 
 void _read_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
 {
-    preempt_enable();
-    _raw_read_unlock(&lock->raw);
+    _read_unlock(lock);
     local_irq_restore(flags);
 }
 
 void _write_lock(rwlock_t *lock)
 {
+    uint32_t x;
+
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_write_trylock(&lock->raw)) )
-    {
-        while ( likely(_raw_rw_is_locked(&lock->raw)) )
+    do {
+        while ( (x = lock->lock) & RW_WRITE_FLAG )
             cpu_relax();
+    } while ( cmpxchg(&lock->lock, x, x|RW_WRITE_FLAG) != x );
+    while ( x != 0 )
+    {
+        cpu_relax();
+        x = lock->lock & ~RW_WRITE_FLAG;
     }
     preempt_disable();
 }
 
 void _write_lock_irq(rwlock_t *lock)
 {
+    uint32_t x;
+
     ASSERT(local_irq_is_enabled());
     local_irq_disable();
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_write_trylock(&lock->raw)) )
+    do {
+        if ( (x = lock->lock) & RW_WRITE_FLAG )
+        {
+            local_irq_enable();
+            while ( (x = lock->lock) & RW_WRITE_FLAG )
+                cpu_relax();
+            local_irq_disable();
+        }
+    } while ( cmpxchg(&lock->lock, x, x|RW_WRITE_FLAG) != x );
+    while ( x != 0 )
     {
-        local_irq_enable();
-        while ( likely(_raw_rw_is_locked(&lock->raw)) )
-            cpu_relax();
-        local_irq_disable();
+        cpu_relax();
+        x = lock->lock & ~RW_WRITE_FLAG;
     }
     preempt_disable();
 }
 
 unsigned long _write_lock_irqsave(rwlock_t *lock)
 {
+    uint32_t x;
     unsigned long flags;
+
     local_irq_save(flags);
     check_lock(&lock->debug);
-    while ( unlikely(!_raw_write_trylock(&lock->raw)) )
+    do {
+        if ( (x = lock->lock) & RW_WRITE_FLAG )
+        {
+            local_irq_restore(flags);
+            while ( (x = lock->lock) & RW_WRITE_FLAG )
+                cpu_relax();
+            local_irq_save(flags);
+        }
+    } while ( cmpxchg(&lock->lock, x, x|RW_WRITE_FLAG) != x );
+    while ( x != 0 )
     {
-        local_irq_restore(flags);
-        while ( likely(_raw_rw_is_locked(&lock->raw)) )
-            cpu_relax();
-        local_irq_save(flags);
+        cpu_relax();
+        x = lock->lock & ~RW_WRITE_FLAG;
     }
     preempt_disable();
     return flags;
@@ -384,9 +423,13 @@ unsigned long _write_lock_irqsave(rwlock
 
 int _write_trylock(rwlock_t *lock)
 {
+    uint32_t x;
+
     check_lock(&lock->debug);
-    if ( !_raw_write_trylock(&lock->raw) )
-        return 0;
+    do {
+        if ( (x = lock->lock) != 0 )
+            return 0;
+    } while ( cmpxchg(&lock->lock, x, x|RW_WRITE_FLAG) != x );
     preempt_disable();
     return 1;
 }
@@ -394,33 +437,32 @@ int _write_trylock(rwlock_t *lock)
 void _write_unlock(rwlock_t *lock)
 {
     preempt_enable();
-    _raw_write_unlock(&lock->raw);
+    if ( cmpxchg(&lock->lock, RW_WRITE_FLAG, 0) != RW_WRITE_FLAG )
+        BUG();
 }
 
 void _write_unlock_irq(rwlock_t *lock)
 {
-    preempt_enable();
-    _raw_write_unlock(&lock->raw);
+    _write_unlock(lock);
     local_irq_enable();
 }
 
 void _write_unlock_irqrestore(rwlock_t *lock, unsigned long flags)
 {
-    preempt_enable();
-    _raw_write_unlock(&lock->raw);
+    _write_unlock(lock);
     local_irq_restore(flags);
 }
 
 int _rw_is_locked(rwlock_t *lock)
 {
     check_lock(&lock->debug);
-    return _raw_rw_is_locked(&lock->raw);
+    return (lock->lock != 0); /* anyone in critical section? */
 }
 
 int _rw_is_write_locked(rwlock_t *lock)
 {
     check_lock(&lock->debug);
-    return _raw_rw_is_write_locked(&lock->raw);
+    return (lock->lock == RW_WRITE_FLAG); /* writer in critical section? */
 }
 
 #ifdef LOCK_PROFILE
