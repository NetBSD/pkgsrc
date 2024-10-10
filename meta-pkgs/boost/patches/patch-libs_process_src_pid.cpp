$NetBSD: patch-libs_process_src_pid.cpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Fix SunOS backend.

--- libs/process/src/pid.cpp.orig	2024-10-10 13:29:12.831306066 +0000
+++ libs/process/src/pid.cpp
@@ -53,6 +53,7 @@
 #include <sys/param.h>
 #include <sys/time.h>
 #include <sys/proc.h>
+#include <fcntl.h>
 #endif
 
 BOOST_PROCESS_V2_BEGIN_NAMESPACE
@@ -640,16 +641,16 @@ std::vector<pid_type> all_pids(boost::sy
             kvm_close(kd);
         }
     };
-
     std::unique_ptr<kvm_t, closer> kd{kvm_open(nullptr, nullptr, nullptr, O_RDONLY, nullptr)};
+
     if (!kd)
     {
         BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
         return vec;
     } 
-    while ((proc_info = kvm_nextproc(kd)))
+    while ((proc_info = kvm_nextproc(kd.get())))
     {
-        if (kvm_kread(kd, (std::uintptr_t)proc_info->p_pidp, &cur_pid, sizeof(cur_pid)) != -1)
+        if (kvm_kread(kd.get(), (std::uintptr_t)proc_info->p_pidp, &cur_pid, sizeof(cur_pid)) != -1)
         {
             vec.insert(vec.begin(), cur_pid.pid_id);
         }
@@ -680,7 +681,7 @@ pid_type parent_pid(pid_type pid, boost:
         BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
         return ppid;
     }
-    if ((proc_info = kvm_getproc(kd, pid)))
+    if ((proc_info = kvm_getproc(kd.get(), pid)))
     {
         ppid = proc_info->p_ppid;
     }
@@ -702,17 +703,17 @@ std::vector<pid_type> child_pids(pid_typ
         }
     };
 
-    std::unique_ptr<kvm_t, closer> kd{kvm_open(nullptr, nullptr, nullptr, O_RDONLY, nullptr);
+    std::unique_ptr<kvm_t, closer> kd{kvm_open(nullptr, nullptr, nullptr, O_RDONLY, nullptr)};
     if (!kd)
     {
         BOOST_PROCESS_V2_ASSIGN_LAST_ERROR(ec)
         return vec;
     }
-    while ((proc_info = kvm_nextproc(kd)))
+    while ((proc_info = kvm_nextproc(kd.get())))
     {
         if (proc_info->p_ppid == pid)
         {
-            if (kvm_kread(kd, (std::uintptr_t)proc_info->p_pidp, &cur_pid, sizeof(cur_pid)) != -1)
+            if (kvm_kread(kd.get(), (std::uintptr_t)proc_info->p_pidp, &cur_pid, sizeof(cur_pid)) != -1)
             {
                 vec.insert(vec.begin(), cur_pid.pid_id);
             }
