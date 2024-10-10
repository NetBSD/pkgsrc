$NetBSD: patch-libs_process_src_ext_cmd.cpp,v 1.2 2024/10/10 14:44:17 jperkin Exp $

* Fix conversion error under NetBSD.
* Fix SunOS backend.

--- libs/process/src/ext/cmd.cpp.orig	2024-10-10 11:51:53.957542478 +0000
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
@@ -365,20 +364,28 @@ shell cmd(boost::process::v2::pid_type p
     char **cmd = nullptr;
     proc *proc_info = nullptr;
     user *proc_user = nullptr;
-    kd = kvm_open(nullptr, nullptr, nullptr, O_RDONLY, nullptr);
+    struct closer
+    {
+        void operator()(kvm_t * kd)
+        {
+            kvm_close(kd);
+        }
+    };
+
+    std::unique_ptr<kvm_t, closer> kd{kvm_open(nullptr, nullptr, nullptr, O_RDONLY, nullptr)};
     if (!kd) {BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec) return {};}
-    if ((proc_info = kvm_getproc(kd, pid))) 
+    if ((proc_info = kvm_getproc(kd.get(), pid)))
     {
-        if ((proc_user = kvm_getu(kd, proc_info))) 
+        if ((proc_user = kvm_getu(kd.get(), proc_info)))
         {
-            if (!kvm_getcmd(kd, proc_info, proc_user, &cmd, nullptr)) 
+            if (!kvm_getcmd(kd.get(), proc_info, proc_user, &cmd, nullptr))
             {
                 int argc = 0;
                 for (int i = 0; cmd[i] != nullptr; i++)
                     argc ++;
                 return make_cmd_shell_::make(
                         {}, argc, cmd,
-                        +[](int, char ** argv) {::free(argv);})
+                        +[](int, char ** argv) {::free(argv);});
             }
             else
                 BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
@@ -389,7 +396,6 @@ shell cmd(boost::process::v2::pid_type p
     else
         BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
     
-    kvm_close(kd);
     return {};
 }
 
