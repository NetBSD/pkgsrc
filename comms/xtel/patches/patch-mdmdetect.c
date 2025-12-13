$NetBSD: patch-mdmdetect.c,v 1.2 2025/12/13 12:38:10 wiz Exp $

--- mdmdetect.c.orig	2012-01-27 10:38:52.533510304 +0100
+++ mdmdetect.c	2012-01-27 10:46:55.339779068 +0100
@@ -102,7 +102,7 @@ static void check_and_lock (char *line)
 #ifdef SVR4
   sprintf (buf, "/dev/%s", line);
   if (stat (buf, &statb) != 0) {
-      fprintf (stderr, "%s: %s\n", buf, sys_errlist[errno]);
+      fprintf (stderr, "%s: %s\n", buf, strerror(errno));
       the_end (1);
   }
 
@@ -119,7 +119,7 @@ static void check_and_lock (char *line)
 
   /* Pose le lock */
   if (!(fplock = fopen (lock_file, "w"))) {
-      fprintf (stderr, "%s: %s\n", lock_file, sys_errlist[errno]);
+      fprintf (stderr, "%s: %s\n", lock_file, strerror(errno));
       the_end (1);
   }
   
@@ -290,7 +290,11 @@ char **av;
     check_and_lock (cp);
 
     sprintf (buf, "/dev/%s", cp);
+#ifdef __NetBSD
+    if ((fd = open (buf, O_RDWR)) < 0) {
+#else
     if ((fd = open (buf, O_RDWR|O_NDELAY)) < 0) {
+#endif
       perror (buf);
       exit (1);
     }
