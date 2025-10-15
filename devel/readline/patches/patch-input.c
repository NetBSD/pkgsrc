$NetBSD: patch-input.c,v 1.3.2.2 2025/10/15 17:17:48 maya Exp $

Fix broken event_hook.
https://lists.gnu.org/archive/html/bug-readline/2025-07/msg00012.html
https://lists.gnu.org/archive/html/bug-readline/2025-07/txtTYu28QVKRX.txt

--- input.c.orig	2025-05-02 13:29:05.000000000 +0000
+++ input.c
@@ -261,13 +261,16 @@ rl_gather_tyi (void)
   input = 0;
   tty = fileno (rl_instream);
 
-  /* Move this up here to give it first shot, but it can't set chars_avail */
+  /* Move this up here to give it first shot, but it can't set chars_avail,
+     so we assume a single character is available. */
   /* XXX - need rl_chars_available_hook? */
   if (rl_input_available_hook)
     {
       result = (*rl_input_available_hook) ();
       if (result == 0)
         result = -1;
+      else
+        chars_avail = 1;
     }
 
 #if defined (HAVE_PSELECT) || defined (HAVE_SELECT)
@@ -285,6 +288,7 @@ rl_gather_tyi (void)
 #endif
       if (result <= 0)
 	return 0;	/* Nothing to read. */
+      result = -1;	/* there is something, so check how many chars below */
     }
 #endif
 
