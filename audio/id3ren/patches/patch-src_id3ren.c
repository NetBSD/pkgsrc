$NetBSD: patch-src_id3ren.c,v 1.1 2020/08/30 10:41:01 jmcneill Exp $

Use PKG_SYSCONFDIR instead of hard-coding /etc.

--- src/id3ren.c.orig	2013-05-21 13:56:15.000000000 +0000
+++ src/id3ren.c
@@ -794,7 +794,7 @@ check_args (int argc, char *argv[])
   #ifdef __WIN32__
         read_config(program_path, CONFIG_GLOBAL);
   #else
-        read_config("/etc", CONFIG_GLOBAL);
+        read_config(PKG_SYSCONFDIR, CONFIG_GLOBAL);
   #endif
   }
 
