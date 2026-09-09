$NetBSD: patch-hp_util_hfp__parser.y,v 1.1 2026/09/09 16:03:19 micha Exp $

Same as for lex (proactively).

--- hp/util/hfp_parser.y.orig	2026-05-01 16:50:10.000000000 +0000
+++ hp/util/hfp_parser.y
@@ -1,6 +1,6 @@
 /*
  * SPDX-FileType: SOURCE
- * SPDX-FileCopyrightText: (c) 2018 Michael Baeuerle
+ * SPDX-FileCopyrightText: (c) 2018-2026 Michael Baeuerle
  * SPDX-License-Identifier: ICU
  */
 
@@ -12,6 +12,9 @@
 ********************************************************************************
 */
 
+/*! Tell headers that they should be POSIX compliant */
+#define _POSIX_C_SOURCE  200112L
+
 #include <stdlib.h>
 #include <stdarg.h>
 #include <stdio.h>
