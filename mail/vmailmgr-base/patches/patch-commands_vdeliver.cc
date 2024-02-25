$NetBSD: patch-commands_vdeliver.cc,v 1.1 2024/02/25 12:09:22 schmonz Exp $

Patch from FreeBSD ports.

--- commands/vdeliver.cc.orig	2015-09-01 16:03:21.000000000 +0000
+++ commands/vdeliver.cc
@@ -262,7 +262,7 @@ void inject(mystring sender, mystring re
     close(pipe2[1]);
     if((dup2(pipe1[0], 0) != 0) || (dup2(pipe2[0], 1) != 1))
       exit(111);
-    execl(qq.c_str(), qq.c_str(), 0);
+    execl(qq.c_str(), qq.c_str(), (char *)0);
     die_temp("Exec of qmail-queue failed.");
   default:
     close(pipe1[0]);
@@ -335,11 +335,12 @@ int cli_main(int, char*[])
 
   if (run_predeliver) {
     int r = execute("vdeliver-predeliver");
-    if(r)
+    if(r) {
       if(r == 99)
-	return 99;
+        return 99;
       else
-	exit_msg("Execution of vdeliver-predeliver failed", r);
+        exit_msg("Execution of vdeliver-predeliver failed", r);
+    }
   }
 
   if(do_delivery) {
