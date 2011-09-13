$NetBSD: patch-Wnn_conv_cvt__head.h,v 1.1 2011/09/13 07:23:16 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/conv/cvt_head.h.orig	2002-03-21 03:32:45.000000000 +0000
+++ Wnn/conv/cvt_head.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -40,11 +40,11 @@
 
 #include "commonhd.h"
 
-#if defined(luna) || defined(DGUX)
+#if defined(luna) || defined(DGUX) || defined(hpux) || defined(sun)
 #ifndef SUPPORT_TWODIGIT_FUNCTIONS
 #define SUPPORT_TWODIGIT_FUNCTIONS
 #endif /* SUPPORT_TWODIGIT_FUNCTIONS */
-#endif /* defined(luna) || defined(DGUX) */
+#endif /* defined(luna) || defined(DGUX) || defined(hpux) || defined(sun) */
 
 #define BITSIZ (sizeof(int) * 8)
 #define CHANGE_MAX 4            /* 変換テーブルの最大個数÷BITSIZを下回らない整数 */
