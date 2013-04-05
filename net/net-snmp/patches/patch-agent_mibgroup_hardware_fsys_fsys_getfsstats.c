$NetBSD: patch-agent_mibgroup_hardware_fsys_fsys_getfsstats.c,v 1.1 2013/04/05 18:20:08 christos Exp $

--- agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2013-04-05 13:53:53.000000000 -0400
+++ agent/mibgroup/hardware/fsys/fsys_getfsstats.c	2013-04-05 13:54:19.000000000 -0400
@@ -154,7 +154,7 @@
         entry->path[sizeof(entry->path)-1] = '\0';
         strlcpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
         entry->device[sizeof(entry->device)-1] = '\0';
-        entry->units = stats[i].f_bsize;    /* or f_frsize */
+        entry->units = stats[i].f_frsize;
         entry->size  = stats[i].f_blocks;
         entry->used  = (stats[i].f_blocks - stats[i].f_bfree);
         /* entry->avail is currently unsigned, so protect against negative
