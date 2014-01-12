$NetBSD: patch-vi_mode.c,v 1.1 2014/01/12 13:30:25 chopps Exp $

Pull in fix for 'cc', 'dd', commands 'yy' from readline git repository (pre-6.3
release). Prior to this 'dd', et al. simply moved to position 0 but did not cut
the text from the line.

--- vi_mode.c.orig	2010-11-21 00:51:39.000000000 +0000
+++ vi_mode.c
@@ -1114,7 +1114,7 @@ rl_domove_read_callback (m)
       rl_beg_of_line (1, c);
       _rl_vi_last_motion = c;
       RL_UNSETSTATE (RL_STATE_VIMOTION);
-      return (0);
+      return (vidomove_dispatch (m));
     }
 #if defined (READLINE_CALLBACKS)
   /* XXX - these need to handle rl_universal_argument bindings */
@@ -1234,11 +1234,19 @@ rl_vi_delete_to (count, key)
       _rl_vimvcxt->motion = '$';
       r = rl_domove_motion_callback (_rl_vimvcxt);
     }
-  else if (vi_redoing)
+  else if (vi_redoing && _rl_vi_last_motion != 'd')	/* `dd' is special */
     {
       _rl_vimvcxt->motion = _rl_vi_last_motion;
       r = rl_domove_motion_callback (_rl_vimvcxt);
     }
+  else if (vi_redoing)		/* handle redoing `dd' here */
+    {
+      _rl_vimvcxt->motion = _rl_vi_last_motion;
+      rl_mark = rl_end;
+      rl_beg_of_line (1, key);
+      RL_UNSETSTATE (RL_STATE_VIMOTION);
+      r = vidomove_dispatch (_rl_vimvcxt);
+    }
 #if defined (READLINE_CALLBACKS)
   else if (RL_ISSTATE (RL_STATE_CALLBACK))
     {
@@ -1316,11 +1324,19 @@ rl_vi_change_to (count, key)
       _rl_vimvcxt->motion = '$';
       r = rl_domove_motion_callback (_rl_vimvcxt);
     }
-  else if (vi_redoing)
+  else if (vi_redoing && _rl_vi_last_motion != 'c')	/* `cc' is special */
     {
       _rl_vimvcxt->motion = _rl_vi_last_motion;
       r = rl_domove_motion_callback (_rl_vimvcxt);
     }
+  else if (vi_redoing)		/* handle redoing `cc' here */
+    {
+      _rl_vimvcxt->motion = _rl_vi_last_motion;
+      rl_mark = rl_end;
+      rl_beg_of_line (1, key);
+      RL_UNSETSTATE (RL_STATE_VIMOTION);
+      r = vidomove_dispatch (_rl_vimvcxt);
+    }
 #if defined (READLINE_CALLBACKS)
   else if (RL_ISSTATE (RL_STATE_CALLBACK))
     {
@@ -1377,6 +1393,19 @@ rl_vi_yank_to (count, key)
       _rl_vimvcxt->motion = '$';
       r = rl_domove_motion_callback (_rl_vimvcxt);
     }
+  else if (vi_redoing && _rl_vi_last_motion != 'y')	/* `yy' is special */
+    {
+      _rl_vimvcxt->motion = _rl_vi_last_motion;
+      r = rl_domove_motion_callback (_rl_vimvcxt);
+    }
+  else if (vi_redoing)			/* handle redoing `yy' here */
+    {
+      _rl_vimvcxt->motion = _rl_vi_last_motion;
+      rl_mark = rl_end;
+      rl_beg_of_line (1, key);
+      RL_UNSETSTATE (RL_STATE_VIMOTION);
+      r = vidomove_dispatch (_rl_vimvcxt);
+    }
 #if defined (READLINE_CALLBACKS)
   else if (RL_ISSTATE (RL_STATE_CALLBACK))
     {
