$NetBSD: patch-filedef.h,v 1.1 2016/05/31 11:44:03 wiz Exp $

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

--- filedef.h.orig	2016-05-21 20:21:52.000000000 +0000
+++ filedef.h
@@ -58,6 +58,8 @@ struct file
     FILE_TIMESTAMP last_mtime;  /* File's modtime, if already known.  */
     FILE_TIMESTAMP mtime_before_update; /* File's modtime before any updating
                                            has been performed.  */
+    unsigned int considered;    /* equal to 'considered' if file has been
+                                   considered on current scan of goal chain */
     int command_flags;          /* Flags OR'd in for cmds; see commands.h.  */
     enum update_status          /* Status of the last attempt to update.  */
       {
@@ -96,8 +98,6 @@ struct file
     unsigned int ignore_vpath:1;/* Nonzero if we threw out VPATH name.  */
     unsigned int pat_searched:1;/* Nonzero if we already searched for
                                    pattern-specific variables.  */
-    unsigned int considered:1;  /* equal to 'considered' if file has been
-                                   considered on current scan of goal chain */
     unsigned int no_diag:1;     /* True if the file failed to update and no
                                    diagnostics has been issued (dontcare). */
   };
