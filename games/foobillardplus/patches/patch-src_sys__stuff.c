$NetBSD: patch-src_sys__stuff.c,v 1.1 2015/09/27 10:07:53 tnn Exp $

Use pkgsrc's installation prefix instead of /proc vooodoo.

--- src/sys_stuff.c.orig	2012-01-02 19:23:49.000000000 +0000
+++ src/sys_stuff.c
@@ -760,6 +760,7 @@ static char data_dir[512];
 
 void enter_data_dir() {
     int success = 1;
+#if 0
 
 #ifdef POSIX
     char proc_exe[20];
@@ -805,6 +806,10 @@ void enter_data_dir() {
         success = 1;
     } while (0);
 
+#endif
+    strncpy(data_dir, "@DATADIR@", sizeof(data_dir));
+    if (chdir(data_dir) < 0)
+        success = 0;
     if (!success) {
         fprintf(stderr,
             "Foobillard++ seems not to be correctly installed\n"
