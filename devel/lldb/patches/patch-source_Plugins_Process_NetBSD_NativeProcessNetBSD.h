$NetBSD: patch-source_Plugins_Process_NetBSD_NativeProcessNetBSD.h,v 1.3 2020/09/23 06:58:46 adam Exp $

Declare StopProcess.

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -86,6 +86,7 @@ public:
   // Interface used by NativeRegisterContext-derived classes.
   static Status PtraceWrapper(int req, lldb::pid_t pid, void *addr = nullptr,
                               int data = 0, int *result = nullptr);
+  static Status StopProcess(lldb::pid_t pid);
 
 private:
   MainLoop::SignalHandleUP m_sigchld_handle;
