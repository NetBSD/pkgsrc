$NetBSD: patch-posix-process_scheduling.adb,v 1.3 2004/06/30 11:23:43 shannonjr Exp $

--- posix-process_scheduling.adb.orig	2002-10-24 02:03:52.000000000 -0600
+++ posix-process_scheduling.adb
@@ -104,7 +104,7 @@ package body POSIX.Process_Scheduling is
    begin
       Check (sched_getparam
         (To_pid_t (Process), Params.Param'Unchecked_Access));
-      return Scheduling_Parameters (Params);
+      return Params;
    end Get_Scheduling_Parameters;
 
    -----------------------------
