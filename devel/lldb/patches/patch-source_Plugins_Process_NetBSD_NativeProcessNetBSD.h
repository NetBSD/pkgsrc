$NetBSD: patch-source_Plugins_Process_NetBSD_NativeProcessNetBSD.h,v 1.4 2022/08/12 08:54:31 pin Exp $

Declare StopProcess.

--- source/Plugins/Process/NetBSD/NativeProcessNetBSD.h.orig	2022-06-22 16:46:24.000000000 +0000
+++ source/Plugins/Process/NetBSD/NativeProcessNetBSD.h
@@ -87,6 +87,7 @@ public:
   // Interface used by NativeRegisterContext-derived classes.
   static Status PtraceWrapper(int req, lldb::pid_t pid, void *addr = nullptr,
                               int data = 0, int *result = nullptr);
+  static Status StopProcess(lldb::pid_t pid);
 
   llvm::Expected<std::string> SaveCore(llvm::StringRef path_hint) override;
 
