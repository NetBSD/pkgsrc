$NetBSD: patch-prnt_hpps_hppsfilter.c,v 1.1 2020/05/14 19:01:48 joerg Exp $

--- prnt/hpps/hppsfilter.c.orig	2020-05-10 23:16:47.425661205 +0000
+++ prnt/hpps/hppsfilter.c
@@ -104,7 +104,7 @@ static void open_tempbookletfile(char *m
     if(ptempbooklet_file == NULL)
     {
             fprintf(stderr, "ERROR: Unable to open temp file %s\n", temp_filename);
-            return 1;
+            return;
     }  
     chmod(temp_filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 
