$NetBSD: patch-canuum_termio.c,v 1.1 2015/10/18 03:58:31 tsutsui Exp $

- Appease prototype warnings.
- Reorganize curses ops.

--- canuum/termio.c.orig	2003-12-27 17:15:21.000000000 +0000
+++ canuum/termio.c
@@ -36,6 +36,11 @@
 #include <stdio.h>
 #if STDC_HEADERS
 #  include <stdlib.h>
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
 #endif /* STDC_HEADERS */
 
 #include "commonhd.h"
@@ -51,15 +56,15 @@
 extern int putchar ();
 
 extern char Term_Name[];
-extern char *Term_UnderScoreStart;
-extern char *Term_UnderScoreEnd;
-extern char *Term_ClrScreen;
-extern char *Term_ClrEofLine;
-extern char *Term_ThrowCursor;
-extern char *Term_StandOutStart;
-extern char *Term_StandOutEnd;
-extern char *Term_BoldOutStart;
-extern char *Term_BoldOutEnd;
+extern const char *Term_UnderScoreStart;
+extern const char *Term_UnderScoreEnd;
+extern const char *Term_ClrScreen;
+extern const char *Term_ClrEofLine;
+extern const char *Term_ThrowCursor;
+extern const char *Term_StandOutStart;
+extern const char *Term_StandOutEnd;
+extern const char *Term_BoldOutStart;
+extern const char *Term_BoldOutEnd;
 static int bold_mode_fun = 0;
 
 int
@@ -73,7 +78,7 @@ openTermData ()
   char errprefix[1024] = "error";
 
   /* for convert_key --- added by Nide 10/3 */
-  if (NULL == (cp = get_kbd_env ()) || 0 != convert_getterm (cp, (0 != verbose_option)))
+  if (NULL == initscr() || NULL == (cp = get_kbd_env ()) || 0 != convert_getterm (cp, (0 != verbose_option)))
     {
       fprintf (stderr, "Cannot get keyboard information.\n");
       return (-1);
@@ -96,13 +101,8 @@ openTermData ()
       return (-1);
     }
 #endif /* CANNA */
-  setupterm (0, 1, &status);
-  /* This seems needless and causes hangs on Solaris8 + ncurses */
-  /* reset_shell_mode (); */
-  if (status != 1)
-    {
-      return (-1);
-    }
+  reset_shell_mode();
+
 #if defined(uniosu)
   if (jterm < 2)
     {                           /* kanji terminal */
@@ -110,7 +110,7 @@ openTermData ()
       return (-1);
     }
 #endif /* defined(uniosu) */
-  if (save_cursor == (char *) NULL || *save_cursor == NULL || restore_cursor == (char *) NULL || *restore_cursor == NULL || change_scroll_region == (char *) NULL || *change_scroll_region == NULL)
+  if (save_cursor == (char *) NULL || *save_cursor == 0 || restore_cursor == (char *) NULL || *restore_cursor == 0 || change_scroll_region == (char *) NULL || *change_scroll_region == 0)
     {
       fprintf (stderr, "Your terminal is not strong enough. Goodbye !\n");
       return (-1);
@@ -175,7 +175,6 @@ openTermData ()
 void
 closeTermData ()
 {
-  resetterm ();
   reset_shell_mode ();
 }
 
