$NetBSD: patch-source_Plugins_Process_NetBSD_NativeProcessNetBSD.cpp,v 1.5 2026/03/25 22:56:25 wiz Exp $

Fix build on NetBSD.
https://github.com/llvm/llvm-project/issues/181586

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2026-02-26 13:08:26.461369868 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -302,8 +302,8 @@ void NativeProcessNetBSD::MonitorSIGTRAP(lldb::pid_t p
       LLDB_LOG(log, "monitoring new thread, pid = {0}, LWP = {1}", pid,
                pst.pe_lwp);
       NativeThreadNetBSD &t = AddThread(pst.pe_lwp);
-      error = t.CopyWatchpointsFrom(
-          static_cast<NativeThreadNetBSD &>(*GetCurrentThread()));
+      error = Status::FromError(t.CopyWatchpointsFrom(
+          static_cast<NativeThreadNetBSD &>(*GetCurrentThread())));
       if (error.Fail()) {
         LLDB_LOG(log, "failed to copy watchpoints to new thread {0}: {1}",
                  pst.pe_lwp, error);
@@ -490,7 +490,7 @@ Status NativeProcessNetBSD::Resume(const ResumeActionL
   Expected<ptrace_siginfo_t> siginfo =
       ComputeSignalInfo(m_threads, resume_actions);
   if (!siginfo)
-    return Status(siginfo.takeError());
+    return Status::FromError(siginfo.takeError());
 
   for (const auto &abs_thread : m_threads) {
     assert(abs_thread && "thread list should not contain NULL threads");
