$NetBSD: patch-src_mongo_util_processinfo__netbsd.cpp,v 1.4 2020/02/01 20:00:08 adam Exp $

Add NetBSD support.

--- src/mongo/util/processinfo_netbsd.cpp.orig	2020-01-27 09:41:08.452841019 +0000
+++ src/mongo/util/processinfo_netbsd.cpp
@@ -26,6 +26,7 @@
  *    exception statement from all source files in the program, then also delete
  *    it in the license file.
  */
+#define _KMEMUSER
 
 #define MONGO_LOG_DEFAULT_COMPONENT ::mongo::logger::LogComponent::kControl
 
@@ -38,7 +39,6 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
 #include <sys/vmmeter.h>
 #include <unistd.h>
 
@@ -85,7 +85,7 @@ template <>
 int getSysctlByIDWithDefault<std::string>(const int* sysctlID,
                                           const int idLen,
                                           const std::string& defaultValue,
-                                          string* result) {
+                                          std::string* result) {
     char value[256] = {0};
     size_t len = sizeof(value);
     if (sysctl(sysctlID, idLen, &value, &len, NULL, 0) == -1) {
@@ -109,7 +109,7 @@ int ProcessInfo::getVirtualMemorySize() 
         return -1;
     }
 
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
     int vss = ((task->p_vm_dsize + task->p_vm_ssize + task->p_vm_tsize) * sysconf(_SC_PAGESIZE)) /
         1048576;
     kvm_close(kd);
@@ -124,7 +124,7 @@ int ProcessInfo::getResidentSize() {
         log() << "Unable to get res mem size: " << err;
         return -1;
     }
-    kinfo_proc* task = kvm_getprocs(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
+    kinfo_proc2* task = kvm_getproc2(kd, KERN_PROC_PID, _pid.toNative(), sizeof(kinfo_proc), &cnt);
     int rss = (task->p_vm_rssize * sysconf(_SC_PAGESIZE)) / 1048576;  // convert from pages to MB
     kvm_close(kd);
     return rss;
@@ -136,7 +136,7 @@ double ProcessInfo::getSystemMemoryPress
 
 void ProcessInfo::SystemInfo::collectSystemInfo() {
     osType = "BSD";
-    osName = "OpenBSD";
+    osName = "NetBSD";
     int mib[2];
 
     mib[0] = CTL_KERN;
