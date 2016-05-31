$NetBSD: patch-remake.c,v 1.3 2016/05/31 11:44:03 wiz Exp $

From 4762480ae9cb8df4878286411f178d32db14eff0 Mon Sep 17 00:00:00 2001
From: Paul Smith <psmith@gnu.org>
Date: Tue, 31 May 2016 06:56:51 +0000
Subject: [SV 47995] Ensure forced double-colon rules work with -j.

The fix for SV 44742 had a side-effect that some double-colon targets
were skipped.  This happens because the "considered" facility assumed
that all targets would be visited on each walk through the dependency
graph: we used a bit for considered and toggled it on each pass; if
we didn't walk the entire graph on every pass the bit would get out
of sync.  The new behavior after SV 44742 might return early without
walking the entire graph.  To fix this I changed the considered value
to an integer which is monotonically increasing: it is then never
possible to incorrectly determine that a previous pass through the
graph already considered the current target.

--- remake.c.orig	2016-05-21 21:34:45.000000000 +0000
+++ remake.c
@@ -57,8 +57,9 @@ unsigned int commands_started = 0;
 static struct goaldep *goal_list;
 static struct dep *goal_dep;
 
-/* Current value for pruning the scan of the goal chain (toggle 0/1).  */
-static unsigned int considered;
+/* Current value for pruning the scan of the goal chain.
+   All files start with considered == 0.  */
+static unsigned int considered = 0;
 
 static enum update_status update_file (struct file *file, unsigned int depth);
 static enum update_status update_file_1 (struct file *file, unsigned int depth);
@@ -90,12 +91,12 @@ update_goal_chain (struct goaldep *goald
 
   goal_list = rebuilding_makefiles ? goaldeps : NULL;
 
-  /* All files start with the considered bit 0, so the global value is 1.  */
-  considered = 1;
-
 #define MTIME(file) (rebuilding_makefiles ? file_mtime_no_search (file) \
                      : file_mtime (file))
 
+  /* Start a fresh batch of consideration.  */
+  ++considered;
+
   /* Update all the goals until they are all finished.  */
 
   while (goals != 0)
@@ -247,10 +248,10 @@ update_goal_chain (struct goaldep *goald
             }
         }
 
-      /* If we reached the end of the dependency graph toggle the considered
-         flag for the next pass.  */
+      /* If we reached the end of the dependency graph update CONSIDERED
+         for the next pass.  */
       if (g == 0)
-        considered = !considered;
+        ++considered;
     }
 
   if (rebuilding_makefiles)
@@ -615,8 +616,8 @@ update_file_1 (struct file *file, unsign
             break;
 
           if (!running)
-            /* The prereq is considered changed if the timestamp has changed while
-               it was built, OR it doesn't exist.  */
+            /* The prereq is considered changed if the timestamp has changed
+               while it was built, OR it doesn't exist.  */
             d->changed = ((file_mtime (d->file) != mtime)
                           || (mtime == NONEXISTENT_MTIME));
 
@@ -650,7 +651,7 @@ update_file_1 (struct file *file, unsign
             /* We may have already considered this file, when we didn't know
                we'd need to update it.  Force update_file() to consider it and
                not prune it.  */
-            d->file->considered = !considered;
+            d->file->considered = 0;
 
             new = update_file (d->file, depth);
             if (new > dep_status)
@@ -1087,7 +1088,7 @@ check_dep (struct file *file, unsigned i
               /* If the target was waiting for a dependency it has to be
                  reconsidered, as that dependency might have finished.  */
               if (file->command_state == cs_deps_running)
-                file->considered = !considered;
+                file->considered = 0;
 
               set_command_state (file, cs_not_started);
             }
