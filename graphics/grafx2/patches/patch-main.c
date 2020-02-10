$NetBSD: patch-main.c,v 1.2 2020/02/10 13:08:10 ryoon Exp $

* Enable non-absolute path execute

--- main.c.orig	2020-02-06 21:01:27.000000000 +0000
+++ main.c
@@ -654,7 +654,7 @@ int Init_program(int argc,char * argv[])
   Init_list_of_pages(Spare.backups);
 
   // Determine the executable directory
-  program_directory = Get_program_directory(argv[0]);
+  program_directory = Get_program_directory("@PREFIX@/bin/grafx2-sdl");
   // Choose directory for data (read only)
   Data_directory = Get_data_directory(program_directory);
   // Choose directory for settings (read/write)
