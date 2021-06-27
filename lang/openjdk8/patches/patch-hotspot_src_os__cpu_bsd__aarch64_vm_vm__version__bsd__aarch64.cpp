$NetBSD: patch-hotspot_src_os__cpu_bsd__aarch64_vm_vm__version__bsd__aarch64.cpp,v 1.1 2021/06/27 18:30:26 tnn Exp $

NetBSD/evbarm-aarch64 support

--- hotspot/src/os_cpu/bsd_aarch64/vm/vm_version_bsd_aarch64.cpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/os_cpu/bsd_aarch64/vm/vm_version_bsd_aarch64.cpp
@@ -201,7 +201,7 @@ const struct cpu_implementers cpu_implem
 	CPU_IMPLEMENTER_NONE,
 };
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 // READ_SPECIALREG is not available from userland on OpenBSD.
 // Hardcode these values to the "lowest common denominator"
 unsigned long VM_Version::os_get_processor_features() {
