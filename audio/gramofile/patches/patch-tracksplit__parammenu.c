$NetBSD: patch-tracksplit__parammenu.c,v 1.1 2021/05/20 19:24:15 nia Exp $

- include missing header for strlen().
- fix format strings.

--- tracksplit_parammenu.c.orig	2000-03-28 21:07:26.000000000 +0000
+++ tracksplit_parammenu.c
@@ -14,6 +14,7 @@
 #include "clrscr.h"
 #include "boxes.h"
 #include "helpline.h"
+#include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #ifndef OLD_CURSES
@@ -212,11 +213,11 @@ tracksplit_parammenu (int *make_use_rms,
 
       stringinput_display (&global_silence_factor_string);
       mvprintw (global_silence_factor_string.y, 2,
-		"Global silence factor (0.1 %)                     :");
+		"Global silence factor (0.1 %%)                    :");
 
       stringinput_display (&local_silence_threshold_string);
       mvprintw (local_silence_threshold_string.y, 2,
-		"Local silence factor (%)                          :");
+		"Local silence factor (%%)                         :");
 
       stringinput_display (&min_silence_blocks_string);
       mvprintw (min_silence_blocks_string.y, 2,
