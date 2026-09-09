$NetBSD: patch-hp_util_hfp__lexer.l,v 1.1 2026/09/09 16:03:19 micha Exp $

lex on SunOS generates code that does not compile without POSIX declaration.

--- hp/util/hfp_lexer.l.orig	2026-05-13 14:05:43.000000000 +0000
+++ hp/util/hfp_lexer.l
@@ -1,7 +1,7 @@
 %{
 /*
  * SPDX-FileType: SOURCE
- * SPDX-FileCopyrightText: (c) 2018-2021 Michael Baeuerle
+ * SPDX-FileCopyrightText: (c) 2018-2026 Michael Baeuerle
  * SPDX-License-Identifier: ICU
  */
 
@@ -9,6 +9,9 @@
 /* ========================================================================== */
 /* Code copied verbatim by lexer */
 
+/*! Tell headers that they should be POSIX compliant */
+#define _POSIX_C_SOURCE  200112L
+
 #include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>
