$NetBSD: patch-include_exec_softmmu__template.h,v 1.1 2014/01/15 18:26:20 wiz Exp $

On NetBSD, uintNN_t types are defined as __uintNN_t
so concatenations "u ## intNN_t" won't work as expected.

--- include/exec/softmmu_template.h.orig	2013-11-27 22:15:55.000000000 +0000
+++ include/exec/softmmu_template.h
@@ -30,24 +30,26 @@
 #define SUFFIX q
 #define LSUFFIX q
 #define SDATA_TYPE  int64_t
+#define DATA_TYPE  uint64_t
 #elif DATA_SIZE == 4
 #define SUFFIX l
 #define LSUFFIX l
 #define SDATA_TYPE  int32_t
+#define DATA_TYPE  uint32_t
 #elif DATA_SIZE == 2
 #define SUFFIX w
 #define LSUFFIX uw
 #define SDATA_TYPE  int16_t
+#define DATA_TYPE  uint16_t
 #elif DATA_SIZE == 1
 #define SUFFIX b
 #define LSUFFIX ub
 #define SDATA_TYPE  int8_t
+#define DATA_TYPE  uint8_t
 #else
 #error unsupported data size
 #endif
 
-#define DATA_TYPE   glue(u, SDATA_TYPE)
-
 /* For the benefit of TCG generated code, we want to avoid the complication
    of ABI-specific return type promotion and always return a value extended
    to the register size of the host.  This is tcg_target_long, except in the
