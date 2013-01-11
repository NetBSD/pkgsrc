$NetBSD: patch-readline_vi__mode.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- readline/vi_mode.c.orig	2013-01-11 12:42:57.000000000 +0000
+++ readline/vi_mode.c
@@ -172,7 +172,7 @@ rl_vi_search (count, key)
 
     default:
       ding ();
-      return;
+      return 0;
     }
 
   vi_histpos = where_history ();
@@ -199,7 +199,7 @@ rl_vi_search (count, key)
 	      maybe_unsave_line ();
 	      rl_clear_message ();
 	      rl_point = save_pos;
-	      return;
+	      return 0;
 	    }
 
 	case CTRL('W'):
@@ -218,7 +218,7 @@ rl_vi_search (count, key)
 	  rl_clear_message ();
 	  rl_point = 0;
 	  ding ();
-	  return;
+	  return 0;
 
 	default:
 	  rl_insert (1, c);
@@ -232,6 +232,7 @@ rl_vi_search (count, key)
 
   vi_last_search = savestring (rl_line_buffer);
   rl_vi_dosearch (rl_line_buffer, dir);
+  return 0;
 }
 
 /* Search for STRING in the history list.  DIR is < 0 for searching
@@ -274,7 +275,7 @@ rl_vi_dosearch (string, dir)
   if (string == 0 || *string == 0 || vi_histpos < 0)
     {
       ding ();
-      return;
+      return 0;
     }
 
   if ((save = vi_history_search_pos (string, dir, vi_histpos + dir)) == -1)
@@ -283,7 +284,7 @@ rl_vi_dosearch (string, dir)
       rl_clear_message ();
       rl_point = 0;
       ding ();
-      return;
+      return 0;
     }
 
   vi_histpos = save;
@@ -305,6 +306,7 @@ rl_vi_dosearch (string, dir)
   rl_end = strlen (rl_line_buffer);
   rl_point = 0;
   rl_clear_message ();
+  return 0;
 }
 
 /* Completion, from vi's point of view. */
@@ -335,19 +337,20 @@ rl_vi_prev_word (count, key)
   if (count < 0)
     {
       rl_vi_next_word (-count, key);
-      return;
+      return 0;
     }
 
   if (rl_point == 0)
     {
       ding ();
-      return;
+      return 0;
     }
 
   if (uppercase_p (key))
     rl_vi_bWord (count);
   else
     rl_vi_bword (count);
+  return 0;
 }
 
 /* Next word in vi mode. */
@@ -357,19 +360,20 @@ rl_vi_next_word (count, key)
   if (count < 0)
     {
       rl_vi_prev_word (-count, key);
-      return;
+      return 0;
     }
 
   if (rl_point >= (rl_end - 1))
     {
       ding ();
-      return;
+      return 0;
     }
 
   if (uppercase_p (key))
     rl_vi_fWord (count);
   else
     rl_vi_fword (count);
+  return 0;
 }
 
 /* Move to the end of the ?next? word. */
@@ -379,13 +383,14 @@ rl_vi_end_word (count, key)
   if (count < 0)
     {
       ding ();
-      return;
+      return 0;
     }
 
   if (uppercase_p (key))
     rl_vi_eWord (count);
   else
     rl_vi_eword (count);
+  return 0;
 }
 
 /* Move forward a word the way that 'W' does. */
@@ -610,7 +615,7 @@ rl_vi_change_case (count, ignore)
 
   /* Don't try this on an empty line. */
   if (rl_point >= rl_end)
-    return;
+    return 0;
 
   while (count-- && rl_point < rl_end)
     {
@@ -631,6 +636,7 @@ rl_vi_change_case (count, ignore)
       else
 	rl_forward (1);
     }
+  return 0;
 }
 
 rl_vi_put (count, key)
@@ -779,13 +785,14 @@ rl_vi_delete_to (count, key)
   if (rl_vi_domove (key, &c))
     {
       ding ();
-      return;
+      return 0;
     }
 
   if ((c != 'l') && (c != '|') && (c != 'h') && rl_mark < rl_end)
     rl_mark++;
 
   rl_kill_text (rl_point, rl_mark);
+  return 0;
 }
 
 rl_vi_change_to (count, key)
@@ -799,7 +806,7 @@ rl_vi_change_to (count, key)
   if (rl_vi_domove (key, &c))
     {
       ding ();
-      return;
+      return 0;
     }
 
   if ((c != 'l') && (c != '|') && (c != 'h') && rl_mark < rl_end)
@@ -809,6 +816,7 @@ rl_vi_change_to (count, key)
   vi_doing_insert = 1;
   rl_kill_text (rl_point, rl_mark);
   rl_vi_insertion_mode ();
+  return 0;
 }
 
 rl_vi_yank_to (count, key)
@@ -822,7 +830,7 @@ rl_vi_yank_to (count, key)
   if (rl_vi_domove (key, &c))
     {
       ding ();
-      return;
+      return 0;
     }
 
   if ((c != 'l') && (c != '|') && (c != 'h') && rl_mark < rl_end)
@@ -833,6 +841,7 @@ rl_vi_yank_to (count, key)
   rl_end_undo_group ();
   rl_do_undo ();
   rl_point = save;
+  return 0;
 }
 
 rl_vi_delete (count)
@@ -842,7 +851,7 @@ rl_vi_delete (count)
   if (rl_end == 0)
     {
       ding ();
-      return;
+      return 0;
     }
 
   end = rl_point + count;
@@ -854,6 +863,7 @@ rl_vi_delete (count)
   
   if (rl_point > 0 && rl_point == rl_end)
     rl_backward (1);
+  return 0;
 }
 
 /* Turn the current line into a comment in shell history.
@@ -932,7 +942,7 @@ rl_vi_char_search (count, key)
 	  if (pos == 0)
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 
 	  pos--;
@@ -952,7 +962,7 @@ rl_vi_char_search (count, key)
 	  if (pos < 0)
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 	}
       else
@@ -960,7 +970,7 @@ rl_vi_char_search (count, key)
 	  if (pos >= rl_end)
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 
 	  pos++;
@@ -980,10 +990,11 @@ rl_vi_char_search (count, key)
 	  if (pos >= (rl_end - 1))
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 	}
     }
+  return 0;
 }
 
 /* Match brackets */
@@ -1002,7 +1013,7 @@ rl_vi_match ()
 	{
 	  rl_point = pos;
 	  ding ();
-	  return;
+	  return 0;
 	}
     }
 
@@ -1023,7 +1034,7 @@ rl_vi_match ()
 	  else
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 	}
     }
@@ -1042,11 +1053,12 @@ rl_vi_match ()
 	  else
 	    {
 	      ding ();
-	      return;
+	      return 0;
 	    }
 	}
     }
   rl_point = pos;
+  return 0;
 }
 
 int
@@ -1073,7 +1085,7 @@ rl_vi_change_char (count, key)
   c = rl_getc (rl_instream);
 
   if (c == '\033' || c == CTRL ('C'))
-    return;
+    return 0;
 
   while (count-- && rl_point < rl_end)
     {
@@ -1086,6 +1098,7 @@ rl_vi_change_char (count, key)
 
       rl_end_undo_group ();
     }
+  return 0;
 }
 
 rl_vi_subst (count, key)
