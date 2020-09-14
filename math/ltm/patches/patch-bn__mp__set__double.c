$NetBSD: patch-bn__mp__set__double.c,v 1.1 2020/09/14 18:23:41 joerg Exp $

--- bn_mp_set_double.c.orig	2020-08-30 18:29:21.656239545 +0000
+++ bn_mp_set_double.c
@@ -3,7 +3,7 @@
 /* LibTomMath, multiple-precision integer library -- Tom St Denis */
 /* SPDX-License-Identifier: Unlicense */
 
-#if defined(__STDC_IEC_559__) || defined(__GCC_IEC_559)
+#if defined(__STDC_IEC_559__) || defined(__GCC_IEC_559) || !defined(__vax__)
 mp_err mp_set_double(mp_int *a, double b)
 {
    uint64_t frac;
