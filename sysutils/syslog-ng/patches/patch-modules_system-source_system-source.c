$NetBSD: patch-modules_system-source_system-source.c,v 1.1 2015/10/29 16:34:13 fhajny Exp $

Add basic NetBSD system() definition.

--- modules/system-source/system-source.c.orig	2015-10-27 08:08:53.000000000 +0000
+++ modules/system-source/system-source.c
@@ -294,6 +294,10 @@ system_generate_system_transports(GStrin
       system_sysblock_add_unix_dgram(sysblock, "/var/run/log", NULL, NULL);
       system_sysblock_add_freebsd_klog(sysblock, u.release);
     }
+  else if (strcmp(u.sysname, "NetBSD") == 0)
+    {
+      system_sysblock_add_unix_dgram(sysblock, "/var/run/log", NULL, NULL);
+    }
   else if (strcmp(u.sysname, "HP-UX") == 0)
     {
       system_sysblock_add_pipe(sysblock, "/dev/log", 2048);
