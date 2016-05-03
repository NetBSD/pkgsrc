$NetBSD: patch-src_fnv_fnv.h,v 1.1 2016/05/03 14:53:05 fhajny Exp $

Use standard int types.

--- src/fnv/fnv.h.orig	2014-07-29 06:26:59.000000000 +0000
+++ src/fnv/fnv.h
@@ -88,7 +88,7 @@ typedef unsigned int u_int32_t;
 /*
  * 32 bit FNV-0 hash type
  */
-typedef u_int32_t Fnv32_t;
+typedef uint32_t Fnv32_t;
 
 
 /*
@@ -130,10 +130,10 @@ typedef unsigned long long u_int64_t;
  * 64 bit FNV-0 hash
  */
 #if defined(HAVE_64BIT_LONG_LONG)
-typedef u_int64_t Fnv64_t;
+typedef uint64_t Fnv64_t;
 #else /* HAVE_64BIT_LONG_LONG */
 typedef struct {
-    u_int32_t w32[2]; /* w32[0] is low order, w32[1] is high order word */
+    uint32_t w32[2]; /* w32[0] is low order, w32[1] is high order word */
 } Fnv64_t;
 #endif /* HAVE_64BIT_LONG_LONG */
 
