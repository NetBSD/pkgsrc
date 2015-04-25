$NetBSD: patch-src_util_u__atomic.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

Fix SunOS atomic macros.

--- src/util/u_atomic.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/util/u_atomic.h
@@ -175,7 +175,7 @@ char _InterlockedCompareExchange8(char v
    sizeof(*v) == sizeof(uint16_t) ? atomic_inc_16((uint16_t *)(v)) : \
    sizeof(*v) == sizeof(uint32_t) ? atomic_inc_32((uint32_t *)(v)) : \
    sizeof(*v) == sizeof(uint64_t) ? atomic_inc_64((uint64_t *)(v)) : \
-                                    (assert(!"should not get here"), 0))
+                                    (assert(!"should not get here"), (void)0))
 
 #define p_atomic_inc_return(v) ((__typeof(*v)) \
    sizeof(*v) == sizeof(uint8_t)  ? atomic_inc_8_nv ((uint8_t  *)(v)) : \
@@ -184,12 +184,12 @@ char _InterlockedCompareExchange8(char v
    sizeof(*v) == sizeof(uint64_t) ? atomic_inc_64_nv((uint64_t *)(v)) : \
                                     (assert(!"should not get here"), 0))
 
-#define p_atomic_dec(v) ((void) \
+#define p_atomic_dec(v) (void) (\
    sizeof(*v) == sizeof(uint8_t)  ? atomic_dec_8 ((uint8_t  *)(v)) : \
    sizeof(*v) == sizeof(uint16_t) ? atomic_dec_16((uint16_t *)(v)) : \
    sizeof(*v) == sizeof(uint32_t) ? atomic_dec_32((uint32_t *)(v)) : \
    sizeof(*v) == sizeof(uint64_t) ? atomic_dec_64((uint64_t *)(v)) : \
-                                    (assert(!"should not get here"), 0))
+                                    (assert(!"should not get here"), (void)0))
 
 #define p_atomic_dec_return(v) ((__typeof(*v)) \
    sizeof(*v) == sizeof(uint8_t)  ? atomic_dec_8_nv ((uint8_t  *)(v)) : \
