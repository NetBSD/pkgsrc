$NetBSD: patch-modules_system-source_system-source.c,v 1.2 2018/08/15 13:08:21 fhajny Exp $

Add basic NetBSD system() definition.

--- modules/system-source/system-source.c.orig	2018-08-10 10:28:08.000000000 +0000
+++ modules/system-source/system-source.c
@@ -295,6 +295,10 @@ system_generate_system_transports(GStrin
       if (!exclude_kernel_messages)
         system_sysblock_add_freebsd_klog(sysblock, u.release);
     }
+  else if (strcmp(u.sysname, "NetBSD") == 0)
+    {
+      system_sysblock_add_unix_dgram(sysblock, "/var/run/log", NULL, NULL);
+    }
   else if (strcmp(u.sysname, "HP-UX") == 0)
     {
       system_sysblock_add_pipe(sysblock, "/dev/log", 2048);
