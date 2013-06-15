$NetBSD: patch-hotspot_src_os__cpu_solaris__x86_vm_atomic__solaris__x86.inline.hpp,v 1.1 2013/06/15 09:31:05 jperkin Exp $

GCC support.

--- hotspot/src/os_cpu/solaris_x86/vm/atomic_solaris_x86.inline.hpp.orig	2013-02-19 23:21:59.000000000 +0000
+++ hotspot/src/os_cpu/solaris_x86/vm/atomic_solaris_x86.inline.hpp
@@ -59,6 +59,8 @@ inline void Atomic::dec_ptr(volatile voi
 // facilitate this, os::is_MP() is passed as an additional argument.  64-bit
 // processors are assumed to be multi-threaded and/or multi-core, so the extra
 // argument is unnecessary.
+// This needs cleaning up - gcc always requires is_mp due to laziness of porter.
+#ifndef _GNU_SOURCE
 #ifndef _LP64
 #define IS_MP_DECL() , int is_mp
 #define IS_MP_ARG()  , (int) os::is_MP()
@@ -66,6 +68,11 @@ inline void Atomic::dec_ptr(volatile voi
 #define IS_MP_DECL()
 #define IS_MP_ARG()
 #endif // _LP64
+#else
+#define IS_MP_DECL() , int is_mp
+#define IS_MP_ARG()  , (int) os::is_MP()
+#endif // _GNU_SOURCE
+
 
 extern "C" {
   jint _Atomic_add(jint add_value, volatile jint* dest IS_MP_DECL());
@@ -96,15 +103,27 @@ inline jlong    Atomic::cmpxchg    (jlon
 #ifdef AMD64
 inline void Atomic::store    (jlong    store_value, jlong*             dest) { *dest = store_value; }
 inline void Atomic::store    (jlong    store_value, volatile jlong*    dest) { *dest = store_value; }
+#ifndef _GNU_SOURCE
 extern "C" jlong _Atomic_add_long(jlong add_value, volatile jlong* dest);
+#else
+extern "C" jlong _Atomic_add_long(jlong add_value, volatile jlong* dest IS_MP_DECL());
+#endif // _GNU_SOURCE
 extern "C" jlong _Atomic_xchg_long(jlong exchange_value, volatile jlong* dest);
 
 inline intptr_t Atomic::add_ptr(intptr_t add_value, volatile intptr_t* dest) {
+#ifndef _GNU_SOURCE
   return (intptr_t)_Atomic_add_long((jlong)add_value, (volatile jlong*)dest);
+#else
+  return (intptr_t)_Atomic_add_long((jlong)add_value, (volatile jlong*)dest IS_MP_ARG());
+#endif // _GNU_SOURCE
 }
 
 inline void*    Atomic::add_ptr(intptr_t add_value, volatile void*     dest) {
+#ifndef _GNU_SOURCE
   return (void*)_Atomic_add_long((jlong)add_value, (volatile jlong*)dest);
+#else
+  return (void*)_Atomic_add_long((jlong)add_value, (volatile jlong*)dest IS_MP_ARG());
+#endif // _GNU_SOURCE
 }
 
 inline intptr_t Atomic::xchg_ptr(intptr_t exchange_value, volatile intptr_t* dest) {
@@ -116,11 +135,19 @@ inline void*    Atomic::xchg_ptr(void*
 }
 
 inline intptr_t Atomic::cmpxchg_ptr(intptr_t exchange_value, volatile intptr_t* dest, intptr_t compare_value) {
+#ifndef _GNU_SOURCE
   return (intptr_t)_Atomic_cmpxchg_long((jlong)exchange_value, (volatile jlong*)dest, (jlong)compare_value);
+#else
+  return (intptr_t)_Atomic_cmpxchg_long((jlong)exchange_value, (volatile jlong*)dest, (jlong)compare_value IS_MP_ARG());
+#endif // _GNU_SOURCE
 }
 
 inline void*    Atomic::cmpxchg_ptr(void*    exchange_value, volatile void*     dest, void*    compare_value) {
+#ifndef _GNU_SOURCE
   return (void*)_Atomic_cmpxchg_long((jlong)exchange_value, (volatile jlong*)dest, (jlong)compare_value);
+#else
+  return (void*)_Atomic_cmpxchg_long((jlong)exchange_value, (volatile jlong*)dest, (jlong)compare_value IS_MP_ARG());
+#endif // _GNU_SOURCE
 }
 
 inline jlong Atomic::load(volatile jlong* src) { return *src; }
@@ -257,6 +284,16 @@ extern "C" {
     #endif // if 0
 #endif // AMD64
   }
+
+  inline void _Atomic_move_long(volatile jlong* src, volatile jlong* dst) {
+    __asm__ volatile (
+      "fildll (%0)"   "\n\t"
+      "fistpll (%1)"
+      :
+      :"r" (src), "r" (dst)
+      :"memory");
+  }
+
 }
 #undef LOCK_IF_MP
 
