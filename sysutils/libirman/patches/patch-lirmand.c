$NetBSD: patch-lirmand.c,v 1.1 2012/10/26 20:29:15 joerg Exp $

--- lirmand.c.orig	2012-10-26 14:22:50.000000000 +0000
+++ lirmand.c
@@ -63,30 +63,30 @@ char *progname = "lirmand";
 
 int lirc = 0;	/* file descriptor */
 int is_daemon = 0;
-FILE *log = NULL;
+FILE *my_log = NULL;
 
 FILE *open_log(void)
 {
   time_t t=time(NULL);
 
-  if (!log) {
-    log = fopen(LIRMAND_LOGFILE, "a");
-    if (log) {
-      fprintf(log, "%s started at %s\n", progname, ctime(&t));
+  if (!my_log) {
+    my_log = fopen(LIRMAND_LOGFILE, "a");
+    if (my_log) {
+      fprintf(my_log, "%s started at %s\n", progname, ctime(&t));
     }
   }
-  return log;
+  return my_log;
 }
 
 void close_log(void)
 {
   time_t t = time(NULL);
   
-  if (log) {
-    fprintf(log, "%s stopped at %s\n", progname, ctime(&t));
-    fclose(log);
+  if (my_log) {
+    fprintf(my_log, "%s stopped at %s\n", progname, ctime(&t));
+    fclose(my_log);
   }
-  log = NULL;
+  my_log = NULL;
 }
 
 
@@ -99,7 +99,7 @@ int debug_printf(char *format, ...)
     return 0;
   
   va_start(va, format);
-  ret = vfprintf(log, format, va);
+  ret = vfprintf(my_log, format, va);
   va_end(va);
 
   return ret;
@@ -114,8 +114,8 @@ int eprintf(char *format, ...)
 
   va_start(va, format);
   if (open_log()) {
-    ret  = fprintf(log, "error: ");
-    ret += vfprintf(log, format, va);
+    ret  = fprintf(my_log, "error: ");
+    ret += vfprintf(my_log, format, va);
   }
   if (!is_daemon) {
     ret  = fprintf(stderr, "%s: ", progname);
