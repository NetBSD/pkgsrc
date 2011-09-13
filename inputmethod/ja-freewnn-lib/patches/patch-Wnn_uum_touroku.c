$NetBSD: patch-Wnn_uum_touroku.c,v 1.1 2011/09/13 07:23:19 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/touroku.c.orig	2001-06-14 18:16:08.000000000 +0000
+++ Wnn/uum/touroku.c
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000
+ * Copyright FreeWnn Project 1999, 2000, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -31,7 +31,19 @@
 
 /* 登録のためのルーチン */
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
 #include <stdio.h>
+#if STDC_HEADERS
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
+#endif /* STDC_HEADERS */
+
 #include "jllib.h"
 #include "commonhd.h"
 #include "sdefine.h"
