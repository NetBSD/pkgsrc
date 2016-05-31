$NetBSD: patch-main.c,v 1.4 2016/05/31 11:44:03 wiz Exp $

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

--- main.c.orig	2016-05-21 20:21:52.000000000 +0000
+++ main.c
@@ -2262,10 +2262,6 @@ main (int argc, char **argv, char **envp
 
             for (i = 0, d = read_files; d != 0; ++i, d = d->next)
               {
-                /* Reset the considered flag; we may need to look at the file
-                   again to print an error.  */
-                d->file->considered = 0;
-
                 if (d->file->updated)
                   {
                     /* This makefile was updated.  */
