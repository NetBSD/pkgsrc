$NetBSD: patch-display.c,v 1.1 2014/08/11 21:29:00 markd Exp $

Readline-6.3 Official Patch 4

The signal handling changes to bash and readline (to avoid running any code
in a signal handler context) cause the cursor to be placed on the wrong
line of a multi-line command after a ^C interrupts editing.

Readline-6.3 Official Patch 6

Using reverse-i-search when horizontal scrolling is enabled does not redisplay
the entire line containing the successful search results.

--- display.c.orig	2013-12-27 18:10:56.000000000 +0000
+++ display.c
@@ -1637,7 +1637,7 @@ update_line (old, new, current_line, oma
   /* If we are changing the number of invisible characters in a line, and
      the spot of first difference is before the end of the invisible chars,
      lendiff needs to be adjusted. */
-  if (current_line == 0 && !_rl_horizontal_scroll_mode &&
+  if (current_line == 0 && /* !_rl_horizontal_scroll_mode && */
       current_invis_chars != visible_wrap_offset)
     {
       if (MB_CUR_MAX > 1 && rl_byte_oriented == 0)
@@ -1825,8 +1825,13 @@ update_line (old, new, current_line, oma
 	      else
 		_rl_last_c_pos += bytes_to_insert;
 
+	      /* XXX - we only want to do this if we are at the end of the line
+		 so we move there with _rl_move_cursor_relative */
 	      if (_rl_horizontal_scroll_mode && ((oe-old) > (ne-new)))
-		goto clear_rest_of_line;
+		{
+		  _rl_move_cursor_relative (ne-new, new);
+		  goto clear_rest_of_line;
+		}
 	    }
 	}
       /* Otherwise, print over the existing material. */
@@ -2677,7 +2682,8 @@ _rl_clean_up_for_exit ()
 {
   if (_rl_echoing_p)
     {
-      _rl_move_vert (_rl_vis_botlin);
+      if (_rl_vis_botlin > 0) /* minor optimization plus bug fix */
+	_rl_move_vert (_rl_vis_botlin);
       _rl_vis_botlin = 0;
       fflush (rl_outstream);
       rl_restart_output (1, 0);
