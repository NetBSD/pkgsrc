$NetBSD: patch-Wnn_uum_basic__op.c,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/basic_op.c.orig	2002-05-12 22:51:17.000000000 +0000
+++ Wnn/uum/basic_op.c
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
@@ -43,10 +43,14 @@ bufferの使い方とかbufferの内容がどのよう
 #include <stdio.h>
 #if STDC_HEADERS
 #  include <stdlib.h>
+#  include <string.h>
 #else
 #  if HAVE_MALLOC_H
 #    include <malloc.h>
 #  endif
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
 #endif /* STDC_HEADERS */
 #include "jllib.h"
 #include "commonhd.h"
