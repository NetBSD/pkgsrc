$NetBSD: patch-src_programs_pkcheck.c,v 1.1 2022/01/25 19:40:46 wiz Exp $

Fix for CVE-2021-4034.
https://gitlab.freedesktop.org/polkit/polkit/-/commit/a2bf5c9c83b6ae46cbd5c779d3055bff81ded683

--- src/programs/pkcheck.c.orig	2018-05-31 11:52:53.000000000 +0000
+++ src/programs/pkcheck.c
@@ -363,6 +363,11 @@ main (int argc, char *argv[])
   local_agent_handle = NULL;
   ret = 126;
 
+  if (argc < 1)
+    {
+      exit(126);
+    }
+
   /* Disable remote file access from GIO. */
   setenv ("GIO_USE_VFS", "local", 1);
 
