$NetBSD: patch-src_vec__avx.h,v 1.1 2024/09/02 16:04:24 nia Exp $

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

--- src/vec_avx.h.orig	2024-04-15 01:07:37.000000000 +0000
+++ src/vec_avx.h
@@ -34,7 +34,7 @@
 
 #include <immintrin.h>
 #include <math.h>
-/*#include "celt/x86/x86cpu.h"*/
+#include "x86/x86cpu.h"
 
 #define MAX_INPUTS (2048)
 
