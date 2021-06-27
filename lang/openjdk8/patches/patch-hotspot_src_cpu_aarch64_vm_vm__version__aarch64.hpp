$NetBSD: patch-hotspot_src_cpu_aarch64_vm_vm__version__aarch64.hpp,v 1.1 2021/06/27 18:30:26 tnn Exp $

NetBSD/evbarm-aarch64 support

--- hotspot/src/cpu/aarch64/vm/vm_version_aarch64.hpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/cpu/aarch64/vm/vm_version_aarch64.hpp
@@ -49,7 +49,7 @@ protected:
   };
   static PsrInfo _psr_info;
   static void get_processor_features();
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   static unsigned long os_get_processor_features();
 #endif
 
