$NetBSD: patch-mdmdetect.c,v 1.1 2012/02/16 18:00:20 hans Exp $

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
   
