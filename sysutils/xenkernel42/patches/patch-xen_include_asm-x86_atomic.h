$NetBSD: patch-xen_include_asm-x86_atomic.h,v 1.1 2015/03/18 15:05:51 joerg Exp $

read_atomic() is used in the condition part of while() loops, so don't
use break here.

--- xen/include/asm-x86/atomic.h.orig	2015-03-17 23:41:49.000000000 +0000
+++ xen/include/asm-x86/atomic.h
@@ -46,12 +46,16 @@ void __bad_atomic_size(void);
 
 #define read_atomic(p) ({                                               \
     typeof(*p) __x;                                                     \
-    switch ( sizeof(*p) ) {                                             \
-    case 1: __x = (typeof(*p))read_u8_atomic((uint8_t *)p); break;      \
-    case 2: __x = (typeof(*p))read_u16_atomic((uint16_t *)p); break;    \
-    case 4: __x = (typeof(*p))read_u32_atomic((uint32_t *)p); break;    \
-    case 8: __x = (typeof(*p))read_u64_atomic((uint64_t *)p); break;    \
-    default: __x = 0; __bad_atomic_size(); break;                       \
+    if ( sizeof(*p) == 1 )                                              \
+        __x = (typeof(*p))read_u8_atomic((uint8_t *)p);                 \
+    else if ( sizeof(*p) == 2 )                                         \
+        __x = (typeof(*p))read_u16_atomic((uint16_t *)p);               \
+    else if ( sizeof(*p) == 4 )                                         \
+        __x = (typeof(*p))read_u32_atomic((uint32_t *)p);               \
+    else if ( sizeof(*p) == 8 )                                         \
+        __x = (typeof(*p))read_u64_atomic((uint64_t *)p);               \
+    else {                                                              \
+        __x = 0; __bad_atomic_size();                                   \
     }                                                                   \
     __x;                                                                \
 })
