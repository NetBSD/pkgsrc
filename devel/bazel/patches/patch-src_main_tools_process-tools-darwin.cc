$NetBSD: patch-src_main_tools_process-tools-darwin.cc,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/main/tools/process-tools-darwin.cc.orig	2023-11-30 00:21:24.455150308 +0000
+++ src/main/tools/process-tools-darwin.cc
@@ -24,6 +24,10 @@
 #include "src/main/tools/logging.h"
 #include "src/main/tools/process-tools.h"
 
+#if defined(__NetBSD__)
+#define kinfo_proc kinfo_proc2
+#endif
+
 int WaitForProcessToTerminate(pid_t pid) {
   int kq;
   if ((kq = kqueue()) == -1) {
@@ -93,7 +97,7 @@ int WaitForProcessGroupToTerminate(pid_t
     if (nprocs == 1) {
       // Found only one process, which must be the leader because we have
       // purposely expect it as a zombie with WaitForProcess.
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
       if (procs->p_pid != pgid) {
 #else
       if (procs->kp_proc.p_pid != pgid) {
