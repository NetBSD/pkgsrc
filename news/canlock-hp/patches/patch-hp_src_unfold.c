$NetBSD: patch-hp_src_unfold.c,v 1.1 2026/09/16 09:47:45 micha Exp $

Remove _POSIX_C_SOURCE (now defined by Makefile).

--- hp/src/unfold.c.orig	2026-05-01 16:33:21.000000000 +0000
+++ hp/src/unfold.c
@@ -4,9 +4,6 @@
  * SPDX-License-Identifier: ICU
  */
 
-/*! Tell headers that they should be POSIX compliant */
-#define _POSIX_C_SOURCE  200112L
-
 /* C99 */
 #include <stdlib.h>
 #include <string.h>
