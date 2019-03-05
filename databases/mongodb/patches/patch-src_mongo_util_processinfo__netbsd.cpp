$NetBSD: patch-src_mongo_util_processinfo__netbsd.cpp,v 1.3 2019/03/05 19:35:58 adam Exp $

NetBSD support.

--- src/mongo/util/processinfo_netbsd.cpp.orig	2019-03-04 22:59:41.311405065 +0000
+++ src/mongo/util/processinfo_netbsd.cpp
@@ -27,6 +27,7 @@
  *    exception statement from all source files in the program, then also delete
  *    it in the license file.
  */
+#define _KMEMUSER
 
 #define MONGO_LOG_DEFAULT_COMPONENT ::mongo::logger::LogComponent::kControl
 
@@ -39,7 +40,6 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
 #include <sys/vmmeter.h>
 #include <unistd.h>
 
@@ -112,7 +112,7 @@ int ProcessInfo::getVirtualMemorySize() 
         return -1;
     }
 
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
     int vss = ((task->p_vm_dsize + task->p_vm_ssize + task->p_vm_tsize) * sysconf(_SC_PAGESIZE)) /
         1048576;
     kvm_close(kd);
@@ -127,7 +127,7 @@ int ProcessInfo::getResidentSize() {
         log() << "Unable to get res mem size: " << err;
         return -1;
     }
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
     int rss = (task->p_vm_rssize * sysconf(_SC_PAGESIZE)) / 1048576;  // convert from pages to MB
     kvm_close(kd);
     return rss;
