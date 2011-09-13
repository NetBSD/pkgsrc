$NetBSD: patch-Wnn_uum_termio.c,v 1.1 2011/09/13 07:23:19 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/termio.c.orig	2002-06-13 21:27:47.000000000 +0000
+++ Wnn/uum/termio.c
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
@@ -35,13 +35,25 @@
 #include <stdio.h>
 #if STDC_HEADERS
 #  include <stdlib.h>
+#  include <string.h>
+#else
+#  if defined (HAVE_STRINGS_H)
+#    include <strings.h>
+#  endif /* HAVE_STRINGS_H */
 #endif /* STDC_HEADERS */
 
 #include "commonhd.h"
 #include "sdefine.h"
 #include "sheader.h"
 
-#ifdef TERMINFO
+/*
+ * tparm() macro for fixed argument prototype systems:
+ * It may not harm on systems that tparm() has variable argument prototype
+ * (or no prototype for compatibility).
+ */
+#define TPARM_3ARGS(func, p1, p2)  tparm((func), (p1), (p2), 0,0,0,0,0,0,0)
+
+#ifdef HAVE_TERMINFO
 #include <stdio.h>
 #include <curses.h>
 #include <term.h>
@@ -67,7 +79,7 @@ openTermData ()
 {
   char *cp, *get_kbd_env ();
   int status;
-  int k;
+  /*  int k; */
   char lcode[10];
   char termchar[20];
   char errprefix[1024] = "error";
@@ -112,9 +124,13 @@ openTermData ()
       fprintf (stderr, "Your terminal is not strong enough. Goodbye !\n");
       return (-1);
     }
+  /*
+   * setenv TERM "${TERM}-j" to prevent starting uum over
+   * uum-controled terminal (disabled for now ...)
+   */
   termchar[0] = 0;
   strcat (termchar, cp);
-  strcat (termchar, "-j");
+  /* strcat (termchar, "-j"); */
   if (setenv ("TERM", termchar, 1) != 0)
     {
 #if HAVE_SNPRINTF
@@ -190,7 +206,7 @@ void
 set_scroll_region (start, end)
      int start, end;
 {
-  tputs (tparm (change_scroll_region, start, end), 1, putchar);
+  tputs (TPARM_3ARGS (change_scroll_region, start, end), 1, putchar);
 }
 
 void
@@ -218,7 +234,7 @@ void
 throw_cur_raw (col, row)
      int col, row;
 {
-  tputs (tparm (cursor_address, row, col), 1, putchar);
+  tputs (TPARM_3ARGS (cursor_address, row, col), 1, putchar);
 }
 
 void
@@ -294,4 +310,4 @@ cursor_normal_raw ()
   tputs (cursor_normal, 1, putchar);
 }
 
-#endif /* TERMINFO */
+#endif /* HAVE_TERMINFO */
