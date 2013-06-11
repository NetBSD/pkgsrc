$NetBSD: patch-cli_cmd__list.cc,v 1.2 2013/06/11 12:58:42 ryoon Exp $

Avoid conflict with C++ list<>.

--- cli/cmd_list.cc.orig	2008-06-06 20:50:55.000000000 +0000
+++ cli/cmd_list.cc
@@ -75,7 +75,7 @@ void cmd_list::list(void)
 
   Processor *pCpu = GetActiveCPU(true);
   if(pCpu)
-    pCpu->list(file_id,pCpu->pc->value,starting_line,ending_line);
+    pCpu->plist(file_id,pCpu->pc->value,starting_line,ending_line);
 
 }
 void cmd_list::list(cmd_options *opt)
