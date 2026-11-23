$NetBSD: patch-src_intel_compiler_gen_gen__private.h,v 1.1 2026/11/23 10:29:52 adam Exp $

Add missing include.

--- src/intel/compiler/gen/gen_private.h.orig	2026-09-07 03:31:53.557406499 +0000
+++ src/intel/compiler/gen/gen_private.h
@@ -8,6 +8,8 @@
 
 #include "dev/intel_device_info.h"
 
+#include <cstddef>
+
 enum {
    GEN_INVALID_HW_REG_TYPE = 0b1111,
 };
