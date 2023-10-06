$NetBSD: patch-source_Plugins_Process_NetBSD_NativeRegisterContextNetBSD__x86__64.cpp,v 1.1 2023/10/06 19:15:20 adam Exp $

submitted upstream as https://reviews.llvm.org/D150032

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp.orig	2023-05-06 11:31:19.992492217 +0200
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD_x86_64.cpp	2023-05-06 11:32:24.079405876 +0200
@@ -409,7 +409,7 @@
     return error;
   }
 
-  RegSetKind set = opt_set.getValue();
+  RegSetKind set = *opt_set;
   error = ReadRegisterSet(set);
   if (error.Fail())
     return error;
@@ -476,7 +476,7 @@
     return error;
   }
 
-  RegSetKind set = opt_set.getValue();
+  RegSetKind set = *opt_set;
   uint64_t new_xstate_bv = 0;
 
   error = ReadRegisterSet(set);
