$NetBSD: patch-src_hotspot_share_jvmci_jvmciEnv.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/jvmci/jvmciEnv.hpp.orig	2025-08-01 08:06:09.852615593 +0000
+++ src/hotspot/share/jvmci/jvmciEnv.hpp
@@ -37,7 +37,7 @@ class CompileTask;
 // Bring the JVMCI compiler thread into the VM state.
 #define JVMCI_VM_ENTRY_MARK                       \
   JavaThread* thread = JavaThread::current(); \
-  MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread)); \
+  AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread)); \
   ThreadInVMfromNative __tiv(thread);       \
   ResetNoHandleMark rnhm;                   \
   HandleMarkCleaner __hm(thread);           \
