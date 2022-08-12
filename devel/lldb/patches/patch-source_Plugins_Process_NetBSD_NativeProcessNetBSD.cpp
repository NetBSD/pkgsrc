$NetBSD: patch-source_Plugins_Process_NetBSD_NativeProcessNetBSD.cpp,v 1.3 2022/08/12 08:54:31 pin Exp $

Provide StopProcess.

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp.orig	2022-06-22 16:46:24.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.cpp
@@ -381,6 +381,29 @@ void NativeProcessNetBSD::MonitorSignal(
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
   Log *log = GetLog(POSIXLog::Ptrace);
@@ -533,7 +556,7 @@ Status NativeProcessNetBSD::Resume(const
   return ret;
 }
 
-Status NativeProcessNetBSD::Halt() { return PtraceWrapper(PT_STOP, GetID()); }
+Status NativeProcessNetBSD::Halt() { return StopProcess(GetID()); }
 
 Status NativeProcessNetBSD::Detach() {
   Status error;
@@ -558,7 +581,7 @@ Status NativeProcessNetBSD::Signal(int s
 }
 
 Status NativeProcessNetBSD::Interrupt() {
-  return PtraceWrapper(PT_STOP, GetID());
+  return StopProcess(GetID());
 }
 
 Status NativeProcessNetBSD::Kill() {
