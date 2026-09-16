$NetBSD: patch-hp_util_canlock-hfp.c,v 1.1 2026/09/16 09:47:45 micha Exp $

Remove _POSIX_C_SOURCE (now defined by Makefile).

--- hp/util/canlock-hfp.c.orig	2026-05-01 16:49:33.000000000 +0000
+++ hp/util/canlock-hfp.c
@@ -4,9 +4,6 @@
  * SPDX-License-Identifier: ICU
  */
 
-/*! Tell headers that they should be POSIX compliant */
-#define _POSIX_C_SOURCE  200112L
-
 
 /* ========================================================================== */
 /* Include files */
