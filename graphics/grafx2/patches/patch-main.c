$NetBSD: patch-main.c,v 1.1 2018/07/17 13:07:50 ryoon Exp $

* Enable non-absolute path execute

--- main.c.orig	2018-05-15 16:51:04.000000000 +0000
+++ main.c
@@ -544,7 +544,7 @@ int Init_program(int argc,char * argv[])
   Init_list_of_pages(Spare.backups);
 
   // Determine the executable directory
-  Set_program_directory(argv[0],program_directory);
+  Set_program_directory("@PREFIX@/bin/grafx2",program_directory);
   // Choose directory for data (read only)
   Set_data_directory(program_directory,Data_directory);
   // Choose directory for settings (read/write)
