$NetBSD: patch-src_interp_engine_interp.h,v 1.1 2014/02/08 09:41:29 obache Exp $

* {u,}int? is defined as __{u,}int? in NetBSD

--- src/interp/engine/interp.h.orig	2009-12-31 18:40:46.000000000 +0000
+++ src/interp/engine/interp.h
@@ -46,11 +46,16 @@
 
 #define STACK_float(offset)    *((float*)&ostack[offset] + IS_BE64)
 #define STACK_uint64_t(offset) *(uint64_t*)&ostack[offset * 2]
+#define STACK___uint64_t(offset) STACK_uint64_t(offset)
 #define STACK_int64_t(offset)  *(int64_t*)&ostack[offset * 2]
+#define STACK___int64_t(offset)  STACK_int64_t(offset)
 #define STACK_double(offset)   *(double*)&ostack[offset * 2]
 #define STACK_uint16_t(offset) (uint16_t)ostack[offset]
+#define STACK___uint16_t(offset) STACK_uint16_t(offset)
 #define STACK_int16_t(offset)  (int16_t)ostack[offset]
+#define STACK___int16_t(offset) STACK_int16_t(offset)
 #define STACK_int8_t(offset)   (int8_t)ostack[offset]
+#define STACK___int8_t(offset)   STACK_int8_t(offset)
 #define STACK_int(offset)      (int)ostack[offset]
 
 #define STACK(type, offset)  STACK_##type(offset)
