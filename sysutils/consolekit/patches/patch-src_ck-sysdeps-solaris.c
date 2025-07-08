$NetBSD: patch-src_ck-sysdeps-solaris.c,v 1.1 2025/07/08 13:01:37 jperkin Exp $

GCC 14 build fixes.

--- src/ck-sysdeps-solaris.c.orig	2025-07-08 12:57:25.282381455 +0000
+++ src/ck-sysdeps-solaris.c
@@ -129,7 +129,7 @@ ck_process_stat_get_tty (CkProcessStat *
 static int
 get_system_vt_major ()
 {
-        static      ret = -1;
+        static int  ret = -1;
         struct stat st;
         int         res;
 
