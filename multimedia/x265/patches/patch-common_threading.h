$NetBSD: patch-common_threading.h,v 1.1 2026/06/27 22:53:56 he Exp $

Try with a variant where we replace __sync* with __atomic*.

--- common/threading.h.orig	2026-04-19 08:29:17.000000000 +0200
+++ common/threading.h	2026-06-26 20:37:17.150566275 +0200
@@ -81,11 +81,11 @@
 #define BSF(id, x)            (id) = ((unsigned long)__builtin_ctz(x))
 #define BSR64(id, x)          (id) = ((unsigned long)__builtin_clzll(x) ^ 63)
 #define BSF64(id, x)          (id) = ((unsigned long)__builtin_ctzll(x))
-#define ATOMIC_OR(ptr, mask)  __sync_fetch_and_or(ptr, mask)
-#define ATOMIC_AND(ptr, mask) __sync_fetch_and_and(ptr, mask)
-#define ATOMIC_INC(ptr)       __sync_add_and_fetch((volatile int32_t*)ptr, 1)
-#define ATOMIC_DEC(ptr)       __sync_add_and_fetch((volatile int32_t*)ptr, -1)
-#define ATOMIC_ADD(ptr, val)  __sync_fetch_and_add((volatile __typeof__(*(ptr))*)ptr, (__typeof__(*(ptr) + 0))(val))
+#define ATOMIC_OR(ptr, mask)  __atomic_fetch_or(ptr, mask, __ATOMIC_SEQ_CST)
+#define ATOMIC_AND(ptr, mask) __atomic_fetch_and(ptr, mask, __ATOMIC_SEQ_CST)
+#define ATOMIC_INC(ptr)       __atomic_add_fetch((volatile int32_t*)ptr, 1, __ATOMIC_SEQ_CST)
+#define ATOMIC_DEC(ptr)       __atomic_add_fetch((volatile int32_t*)ptr, -1, __ATOMIC_SEQ_CST)
+#define ATOMIC_ADD(ptr, val)  __atomic_fetch_add((volatile __typeof__(*(ptr))*)ptr, (__typeof__(*(ptr) + 0))(val), __ATOMIC_SEQ_CST)
 #define GIVE_UP_TIME()        usleep(0)
 
 #elif defined(_MSC_VER)       /* Windows atomic intrinsics */
