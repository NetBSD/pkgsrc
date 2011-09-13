$NetBSD: patch-Wnn_include_wnn__os.h,v 1.1 2011/09/13 07:23:17 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/include/wnn_os.h.orig	2005-06-12 17:14:23.000000000 +0000
+++ Wnn/include/wnn_os.h
@@ -10,9 +10,9 @@
  *                 1987, 1988, 1989, 1990, 1991, 1992
  * Copyright OMRON Corporation. 1987, 1988, 1989, 1990, 1991, 1992, 1999
  * Copyright ASTEC, Inc. 1987, 1988, 1989, 1990, 1991, 1992
- * Copyright FreeWnn Project 1999, 2000, 2002, 2005
+ * Copyright FreeWnn Project 1999, 2000, 2002, 2005, 2006
  *
- * Maintainer:  FreeWnn Project   <freewnn@tomo.gr.jp>
+ * Maintainer:  FreeWnn Project
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
@@ -50,11 +50,6 @@
 #  include <sys/param.h>
 #endif
 
-#ifdef TERMINFO
-#include <curses.h>
-#include <term.h>
-#endif
-
 /* strchr vs. index, etc. */
 #if (HAVE_MEMSET) && !(HAVE_BZERO)
 #  define bzero(adr,n)  memset((adr),0,(n))
