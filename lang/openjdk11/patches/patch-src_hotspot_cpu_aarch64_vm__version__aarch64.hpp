$NetBSD: patch-src_hotspot_cpu_aarch64_vm__version__aarch64.hpp,v 1.1 2019/12/04 12:19:25 tnn Exp $

NetBSD/evbarm-aarch64 support

--- src/hotspot/cpu/aarch64/vm_version_aarch64.hpp.orig	2019-10-16 18:31:09.000000000 +0000
+++ src/hotspot/cpu/aarch64/vm_version_aarch64.hpp
@@ -47,7 +47,7 @@ protected:
   };
   static PsrInfo _psr_info;
   static void get_processor_features();
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   static unsigned long os_get_processor_features();
 #endif
 
