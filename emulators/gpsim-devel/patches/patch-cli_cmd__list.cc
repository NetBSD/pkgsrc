$NetBSD: patch-cli_cmd__list.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- cli/cmd_list.cc.orig	2005-08-31 14:46:33.000000000 +0000
+++ cli/cmd_list.cc
@@ -76,7 +76,7 @@ void cmd_list::list(void)
   if(!have_cpu(1))
     return;
 
-  GetActiveCPU()->list(file_id,GetActiveCPU()->pc->value,starting_line,ending_line);
+  GetActiveCPU()->plist(file_id,GetActiveCPU()->pc->value,starting_line,ending_line);
 
 }
 void cmd_list::list(cmd_options *opt)
