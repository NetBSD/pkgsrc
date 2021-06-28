$NetBSD: patch-src_hotspot_os__cpu_bsd__arm_vm__version__bsd__arm__32.cpp,v 1.1 2021/06/28 22:53:05 tnn Exp $

fix arch detection of NetBSD 32-bit ARM targets

--- src/hotspot/os_cpu/bsd_arm/vm_version_bsd_arm_32.cpp.orig	2021-04-24 02:47:22.000000000 +0000
+++ src/hotspot/os_cpu/bsd_arm/vm_version_bsd_arm_32.cpp
@@ -35,7 +35,7 @@ void VM_Version::get_os_cpu_info() {
 
   int mib[2];
   size_t len;
-  char machine[8]; // 8 chars max : "arm" + "v6|v7" + "|eb" + '\0'
+  char machine[11]; // 11 chars max : "earm" + "v6|v7" + "|hf" + "|eb" + '\0'
 
   // Support for multiple calls in the init phase
   if (done) return;
@@ -55,6 +55,9 @@ void VM_Version::get_os_cpu_info() {
   } else if (strncmp(machine, "armv", 4) == 0 &&
       machine[4] >= '5' && machine[4] <= '9') {
     _arm_arch = (int)(machine[4] - '0');
+  }  else if (strncmp(machine, "earmv", 5) == 0 &&
+      machine[5] >= '5' && machine[5] <= '9') {
+    _arm_arch = (int)(machine[5] - '0');
   }
 }
 
