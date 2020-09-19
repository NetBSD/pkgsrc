$NetBSD: patch-source_Plugins_Process_NetBSD_NativeProcessNetBSD.cpp,v 1.1 2020/09/19 17:25:02 he Exp $

Provide StopProcess.

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -344,6 +344,29 @@ void NativeProcessNetBSD::MonitorSignal(
   SetState(StateType::eStateStopped, true);
 }
 
+Status NativeProcessNetBSD::StopProcess(lldb::pid_t pid) {
+#ifdef PT_STOP
+  return PtraceWrapper(PT_STOP, pid);
+#else
+  Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PTRACE));
+  int ret;
+  Status error;
+
+  errno = 0;
+  ret = kill(pid, SIGSTOP);
+
+  if (ret == -1)
+    error.SetErrorToErrno();
+
+  LLDB_LOG(log, "kill({0}, SIGSTOP)", pid);
+
+  if (error.Fail())
+    LLDB_LOG(log, "kill() failed: {0}", error);
+
+  return error;  
+#endif
+}
+
 Status NativeProcessNetBSD::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
                                           int data, int *result) {
   Log *log(ProcessPOSIXLog::GetLogIfAllCategoriesSet(POSIX_LOG_PTRACE));
@@ -497,7 +520,7 @@ Status NativeProcessNetBSD::Resume(const
 }
 
 Status NativeProcessNetBSD::Halt() {
-  return PtraceWrapper(PT_STOP, GetID());
+  return StopProcess(GetID());
 }
 
 Status NativeProcessNetBSD::Detach() {
@@ -523,7 +546,7 @@ Status NativeProcessNetBSD::Signal(int s
 }
 
 Status NativeProcessNetBSD::Interrupt() {
-  return PtraceWrapper(PT_STOP, GetID());
+  return StopProcess(GetID());
 }
 
 Status NativeProcessNetBSD::Kill() {
