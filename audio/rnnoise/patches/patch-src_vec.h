$NetBSD: patch-src_vec.h,v 1.1 2024/09/02 16:04:24 nia Exp $

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

--- src/vec.h.orig	2024-04-15 01:07:37.000000000 +0000
+++ src/vec.h
@@ -30,6 +30,7 @@
 #define VEC_H
 
 #include "opus_types.h"
+#include "common.h"
 #include <math.h>
 #include "arch.h"
 #include "x86/x86_arch_macros.h"
@@ -41,8 +42,6 @@
 #include "vec_neon.h"
 #else
 
-#include "os_support.h"
-
 #define MAX_INPUTS (2048)
 
 #define NO_OPTIMIZATIONS
@@ -50,7 +49,7 @@
 static inline void sgemv16x1(float *out, const float *weights, int rows, int cols, int col_stride, const float *x)
 {
    int i, j;
-   OPUS_CLEAR(out, rows);
+   RNN_CLEAR(out, rows);
    for (i=0;i<rows;i+=16)
    {
       for (j=0;j<cols;j++)
@@ -84,7 +83,7 @@ static inline void sgemv16x1(float *out,
 static inline void sgemv8x1(float *out, const float *weights, int rows, int cols, int col_stride, const float *x)
 {
    int i, j;
-   OPUS_CLEAR(out, rows);
+   RNN_CLEAR(out, rows);
    for (i=0;i<rows;i+=8)
    {
       for (j=0;j<cols;j++)
@@ -124,7 +123,7 @@ static inline void sgemv(float *out, con
 static inline void sparse_sgemv8x4(float *out, const float *w, const int *idx, int rows, const float *x)
 {
    int i, j;
-   OPUS_CLEAR(out, rows);
+   RNN_CLEAR(out, rows);
    for (i=0;i<rows;i+=8)
    {
       int cols;
