$NetBSD: patch-posix-process_times.adb,v 1.3 2004/06/30 11:23:43 shannonjr Exp $

--- posix-process_times.adb.orig	2002-10-24 02:03:52.000000000 -0600
+++ posix-process_times.adb
@@ -64,7 +64,7 @@ package body POSIX.Process_Times is
       t : Process_Times;
    begin
       t.Elapsed_Real_Time := times (t.tms'Unchecked_Access);
-      return Process_Times (t);
+      return t;
    end Get_Process_Times;
 
    ----------------------------
