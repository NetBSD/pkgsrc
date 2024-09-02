$NetBSD: patch-src_vec__neon.h,v 1.1 2024/09/02 16:04:24 nia Exp $

From: "Timothy B. Terriberry" <tterribe@xiph.org>
Date: Mon, 15 Apr 2024 11:27:25 -0700
Subject: [PATCH] Fix compilation errors.

vec_avx.h needs x86cpu.h, and x86cpu.h needs to detect SSE2 (or
 greater) without the Opus macros.
Also, nobody was defining OPUS_CLEAR (but several things were
 including the non-existent os_support.h where it is defined in
 libopus), so replace those calls with RNN_CLEAR and remove the
 erroneous includes.
Take the opportunity to hoist OPUS_GNUC_PREREQ to common.h, too,
 since it is needed in multiple places now.

--- src/vec_neon.h.orig	2024-04-15 01:07:37.000000000 +0000
+++ src/vec_neon.h
@@ -32,7 +32,8 @@
 #define VEC_NEON_H
 
 #include <arm_neon.h>
-#include "os_support.h"
+#include "opus_types.h"
+#include "common.h"
 
 #if defined(__arm__) && !defined(__aarch64__) && (__ARM_ARCH < 8 || !defined(__clang__))
 /* Emulate vcvtnq_s32_f32() for ARMv7 Neon. */
@@ -302,7 +303,7 @@ static inline void sgemv(float *out, con
 static inline void sparse_sgemv8x4(float *out, const float *w, const int *idx, int rows, const float *x)
 {
    int i, j;
-   OPUS_CLEAR(out, rows);
+   RNN_CLEAR(out, rows);
    for (i=0;i<rows;i+=8)
    {
       int cols;
