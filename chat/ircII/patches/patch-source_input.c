$NetBSD: patch-source_input.c,v 1.1 2014/03/12 07:22:34 mrg Exp $

fix a problem with the input line when it goes beyond the screen size

Index: source/input.c
===================================================================
RCS file: /home/cvs/ircii/source/input.c,v
retrieving revision 1.55
retrieving revision 1.56
diff -p -r1.55 -r1.56
*** source/input.c	30 Dec 2013 16:42:38 -0000	1.55
--- source/input.c	30 Jan 2014 10:13:06 -0000	1.56
*************** update_input(update)
*** 488,493 ****
--- 484,491 ----
  			}
  		}
  		VisBuf[optr] = '\0';
+ 		if (old_cursor_pos > inputdata->cursor_x)
+ 			old_cursor_pos = 0;
  		term_move_cursor(old_cursor_pos, inputdata->cursor_y);
  		written = output_line(VisBuf + old_cursor_pos, 0);
  		if (term_clear_to_eol() && written < current_screen->co)
