$NetBSD: patch-xen_include_asm-x86_spinlock.h,v 1.1 2017/02/14 21:38:34 joerg Exp $

From c86aa9a250ca0c87760b369f295f67ae01542fa9.

--- xen/include/asm-x86/spinlock.h.orig	2017-02-10 22:33:31.337508849 +0000
+++ xen/include/asm-x86/spinlock.h
@@ -2,7 +2,8 @@
 #define __ASM_SPINLOCK_H
 
 #define _raw_read_unlock(l) \
-    asm volatile ( "lock; dec%z0 %0" : "+m" ((l)->lock) :: "memory" )
+    BUILD_BUG_ON(sizeof((l)->lock) != 4); /* Clang doesn't support %z in asm. */ \
+    asm volatile ( "lock; decl %0" : "+m" ((l)->lock) :: "memory" )
 
 /*
  * On x86 the only reordering is of reads with older writes.  In the
