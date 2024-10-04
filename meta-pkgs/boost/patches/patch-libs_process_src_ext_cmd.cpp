$NetBSD: patch-libs_process_src_ext_cmd.cpp,v 1.1 2024/10/04 03:26:54 ryoon Exp $

* Fix conversion error under NetBSD.

--- libs/process/src/ext/cmd.cpp.orig	2024-09-04 03:57:14.583580599 +0000
+++ libs/process/src/ext/cmd.cpp
@@ -299,7 +299,6 @@ shell cmd(boost::process::v2::pid_type p
 shell cmd(boost::process::v2::pid_type pid, boost::system::error_code & ec)
 {
 
-    std::vector<std::string> vec;
     int cntp = 0;
     kinfo_proc2 *proc_info = nullptr;
     struct closer
@@ -312,7 +311,7 @@ shell cmd(boost::process::v2::pid_type p
 
     std::unique_ptr<kvm_t, closer> kd{kvm_openfiles(nullptr, nullptr, nullptr, KVM_NO_FILES, nullptr)};
 
-    if (!kd) {BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec) return vec;}
+    if (!kd) {BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec) return {};}
     if ((proc_info = kvm_getproc2(kd.get(), KERN_PROC_PID, pid, sizeof(struct kinfo_proc2), &cntp))) 
     {
         char **cmd = kvm_getargv2(kd.get(), proc_info, 0);
@@ -323,7 +322,7 @@ shell cmd(boost::process::v2::pid_type p
     }
     else
         BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
-    return vec;
+    return {};
 }
     
 #elif defined(__OpenBSD__)
