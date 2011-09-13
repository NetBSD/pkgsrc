$NetBSD: patch-Wnn_uum_epilogue.c,v 1.1 2011/09/13 07:23:18 mef Exp $

(Almost) Automatic generation to sourceforge cvs Repository 2011/05/31

--- Wnn/uum/epilogue.c.orig	2001-06-14 18:16:06.000000000 +0000
+++ Wnn/uum/epilogue.c
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
@@ -49,7 +49,7 @@ epilogue_no_close ()
   set_scroll_region (0, crow + conv_lines - 1);
   kk_restore_cursor ();
   flush ();
-#ifdef TERMINFO
+#ifdef HAVE_TERMINFO
   closeTermData ();
 #endif
 }
