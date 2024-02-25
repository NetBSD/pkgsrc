$NetBSD: patch-commands_vdeliver.cc,v 1.2 2024/02/25 12:44:44 schmonz Exp $

Patches from FreeBSD ports and GitHub PR #1.

--- commands/vdeliver.cc.orig	2015-09-01 16:03:21.000000000 +0000
+++ commands/vdeliver.cc
@@ -176,7 +176,7 @@ void deliver_partial()
   const mystring hostname = make_hostname();
   pid_t pid = getpid();
   for(;; sleep(2)) {
-    partname = "/" + mystring(itoa(time(0))) + "." + itoa(pid)
+    partname = "/" + mystring(itoa(time(0))) + "." + mystring(itoa(pid))
       + "." + hostname;
     
     mystring newfile = newdir + partname;
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
