$NetBSD: patch-agent_mibgroup_hardware_fsys_fsys_getfsstats.c,v 1.2 2014/08/22 16:27:18 adam Exp $

--- agent/mibgroup/hardware/fsys/fsys_getfsstats.c.orig	2014-02-20 00:36:42.000000000 +0000
+++ agent/mibgroup/hardware/fsys/fsys_getfsstats.c
@@ -154,7 +154,11 @@ netsnmp_fsys_arch_load( void )
         entry->path[sizeof(entry->path)-1] = '\0';
         strlcpy( entry->device, stats[i].f_mntfromname, sizeof(entry->device));
         entry->device[sizeof(entry->device)-1] = '\0';
+#ifdef __APPLE__
         entry->units = stats[i].f_bsize;    /* or f_frsize */
+#else
+        entry->units = stats[i].f_frsize;
+#endif
         entry->size  = stats[i].f_blocks;
         entry->used  = (stats[i].f_blocks - stats[i].f_bfree);
         /* entry->avail is currently unsigned, so protect against negative
