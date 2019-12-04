$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_vm__version__bsd__aarch64.cpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

TODO processor feature detection for aarch64

--- src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/vm_version_bsd_aarch64.cpp
@@ -186,7 +186,7 @@ const struct cpu_implementers cpu_implem
 	CPU_IMPLEMENTER_NONE,
 };
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 // READ_SPECIALREG is not available from userland on OpenBSD.
 // Hardcode these values to the "lowest common denominator"
 unsigned long VM_Version::os_get_processor_features() {
