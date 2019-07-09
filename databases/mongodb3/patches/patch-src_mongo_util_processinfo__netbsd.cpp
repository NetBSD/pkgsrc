$NetBSD: patch-src_mongo_util_processinfo__netbsd.cpp,v 1.2 2019/07/09 07:28:30 adam Exp $

Add NetBSD support.

--- src/mongo/util/processinfo_netbsd.cpp.orig	2019-07-08 19:34:24.000000000 +0000
+++ src/mongo/util/processinfo_netbsd.cpp
@@ -25,6 +25,8 @@
  *    then also delete it in the license file.
  */
 
+#define _KMEMUSER
+
 #define MONGO_LOG_DEFAULT_COMPONENT ::mongo::logger::LogComponent::kControl
 
 #include <cstdlib>
@@ -36,7 +38,6 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
 #include <sys/vmmeter.h>
 #include <unistd.h>
 
@@ -109,7 +110,7 @@ int ProcessInfo::getVirtualMemorySize() 
         return -1;
     }
 
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc2), &cnt);
     kvm_close(kd);
     return ((task->p_vm_dsize + task->p_vm_ssize + task->p_vm_tsize) * sysconf(_SC_PAGESIZE)) /
         1048576;
@@ -123,7 +124,7 @@ int ProcessInfo::getResidentSize() {
         log() << "Unable to get res mem size: " << err;
         return -1;
     }
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc2), &cnt);
     kvm_close(kd);
     return (task->p_vm_rssize * sysconf(_SC_PAGESIZE)) / 1048576;  // convert from pages to MB
 }
@@ -134,7 +135,7 @@ double ProcessInfo::getSystemMemoryPress
 
 void ProcessInfo::SystemInfo::collectSystemInfo() {
     osType = "BSD";
-    osName = "OpenBSD";
+    osName = "NetBSD";
     int mib[2];
 
     mib[0] = CTL_KERN;
