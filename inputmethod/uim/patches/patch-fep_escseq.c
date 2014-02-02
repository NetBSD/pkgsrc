$NetBSD: patch-fep_escseq.c,v 1.1 2014/02/02 10:47:24 obache Exp $

* termios.h is required for struct termios
* pass 9 parameters to tparm(3) for portability 

--- fep/escseq.c.orig	2013-06-30 04:26:09.000000000 +0000
+++ fep/escseq.c
@@ -61,6 +61,9 @@
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
+#ifdef HAVE_TERMIOS_H
+#include <termios.h>
+#endif
 
 #include "uim-fep.h"
 #include "draw.h"
@@ -964,7 +967,7 @@ void put_cursor_address(int row, int col
   if (row == s_cursor.row && col == s_cursor.col && col < g_win->ws_col - 2) {
     return;
   }
-  tmp = tparm(cursor_address, row, col);
+  tmp = tparm(cursor_address, row, col, 0, 0, 0, 0, 0, 0, 0);
   my_putp(tmp);
   s_cursor.row = row;
   s_cursor.col = col;
@@ -985,7 +988,7 @@ void put_insert(int n)
   if (n <= 0) {
     return;
   }
-  tmp = tparm(parm_ich, n);
+  tmp = tparm(parm_ich, n, 0, 0, 0, 0, 0, 0, 0, 0);
   my_putp(tmp);
   debug(("<ins %d>", n));
 }
@@ -1007,7 +1010,7 @@ void put_delete(int n)
     change_background_attr(&s_attr, s_attr_uim);
   }
 
-  tmp = tparm(parm_dch, n);
+  tmp = tparm(parm_dch, n, 0, 0, 0, 0, 0, 0, 0, 0);
   my_putp(tmp);
   debug(("<del %d>", n));
 }
@@ -1036,7 +1039,7 @@ void put_goto_lastline(int col)
   if (row == s_cursor.row && col == s_cursor.col) {
     return;
   }
-  tmp = tparm(cursor_address, row, col);
+  tmp = tparm(cursor_address, row, col, 0, 0, 0, 0, 0, 0, 0);
   my_putp(tmp);
   s_cursor.row = row;
   s_cursor.col = col;
@@ -1103,7 +1106,7 @@ void put_clear_to_end_of_line(int width)
  */
 void put_change_scroll_region(int start, int end)
 {
-  const char *tmp = tparm(change_scroll_region, start, end);
+  const char *tmp = tparm(change_scroll_region, start, end, 0, 0, 0, 0, 0, 0, 0);
   my_putp(tmp);
   s_cursor.row = s_cursor.col = 0;
   debug(("<region %d %d>", start, end));
